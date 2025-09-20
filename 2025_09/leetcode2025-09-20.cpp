#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

struct TupleHash {
    size_t operator()(const tuple<int, int, int>& t) const {
        auto [a, b, c] = t;
        return hash<int>()(a) ^ hash<int>()(b) ^ hash<int>()(c);
    }
};

class Router {
private:
// 注意，由于c++中tuple<int, int, int>类型无法哈希化，因此需要自定义tuple的哈希函数
    int memoLim;
    deque<tuple<int, int, int>> allPacket;
    unordered_map<int, vector<int>> dest_packet;
    unordered_map<tuple<int, int, int>, int, TupleHash> isPacketIn;
public:
    Router(int memoryLimit) {
        memoLim = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto curPacket = make_tuple(source, destination, timestamp);
        if (isPacketIn[curPacket] == 1){
            return false;
        }
        allPacket.push_back(curPacket);
        dest_packet[destination].push_back(timestamp);
        isPacketIn[curPacket] = 1;
        if (allPacket.size() > memoLim){
            forwardPacket();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if (allPacket.empty()){
            return {};
        }
        auto[curSource, curDest, curTimestamp] = allPacket.front();
        isPacketIn[allPacket.front()] = 0;
        allPacket.pop_front();
        dest_packet[curDest].erase(dest_packet[curDest].begin());
        return {curSource, curDest, curTimestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int l = lower_bound(dest_packet[destination].begin(), dest_packet[destination].end(), startTime)-dest_packet[destination].begin();
        int r = upper_bound(dest_packet[destination].begin(), dest_packet[destination].end(), endTime)-dest_packet[destination].begin()-1;
        return r-l+1;
    }
};

int main(){
    int memoryLimit = 3;
    Router r(memoryLimit);
    vector<string> op = {"addPacket","addPacket","addPacket","addPacket","addPacket","forwardPacket","addPacket","getCount"};
    vector<vector<int>> num = {{1,4,90},{2,5,90},{1,4,90},{3,5,95},{4,5,105},{},{5,2,110},{5,100,110}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "addPacket"){
            cout << r.addPacket(num[i][0], num[i][1], num[i][2]) << endl;
        }
        if (op[i] == "forwardPacket"){
            vector<int> cur = r.forwardPacket();
            cout << cur[0] << " " << cur[1] << " " << cur[2] << endl;
        }
        else{
            cout << r.getCount(num[i][0], num[i][1], num[i][2]) << endl;
        }
    }
}
