#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> freeRooms, usingRooms;
        for (long long i=0; i<n; i++){
            freeRooms.emplace(i, 0);
        }
        unordered_map<long long, long long> cnt;
        for (auto& m : meetings){
            long long start = m[0], end = m[1];
            while (!usingRooms.empty() && usingRooms.top().first <= start){
                pair<long long, long long> tmp = usingRooms.top();
                usingRooms.pop();
                freeRooms.emplace(tmp.second, tmp.first);
            }

            long long length = end-start;
            if (!freeRooms.empty()){
                pair<long long, long long> tmp = freeRooms.top();
                freeRooms.pop();
                usingRooms.emplace(end, tmp.first);
                cnt[tmp.first]++;
            }
            else{
                if (!usingRooms.empty()){
                    pair<long long, long long> tmp = usingRooms.top();
                    usingRooms.pop();
                    usingRooms.emplace(tmp.first+length, tmp.second);
                    cnt[tmp.second]++;
                }
            }
        }

        long long maxTimes = 0, res = 0;
        for (long long i=0; i<n; i++){
            if (cnt.count(i) && cnt[i] > maxTimes){
                maxTimes = cnt[i];
                res = i;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 2;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    cout << s.mostBooked(n, meetings) << endl;
}
