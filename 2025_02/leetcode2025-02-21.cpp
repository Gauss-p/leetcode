#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> white, F;
    unordered_map<long long, int> memo;
    int l;
    int dfs(int carpet, int floorNum){
        if (carpet==0) return white[floorNum];
        if (floorNum==0 || carpet*l>=floorNum) return 0;
        long long key = (long long)carpet<<32 | floorNum;
        if (memo.count(key)){
            return memo[key];
        }
        int res = dfs(carpet, floorNum-1)+F[floorNum-1];
        if (floorNum >= l){
            res = min(res, dfs(carpet-1, floorNum-l));
        }
        memo[key] = res;
        return res;
    }
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        l = carpetLen;
        int n = floor.size();
        for (auto& c : floor){
            F.push_back(c-'0');
        }
        white.resize(n+1, 0);
        for (int i=0; i<n; i++){
            white[i+1] = white[i]+F[i];
        }
        return dfs(numCarpets, n);
    }
};

int main(){
    Solution s;
    string floor = "10110101";
    int numCarpets=2, carpetLen=2;
    cout << s.minimumWhiteTiles(floor, numCarpets, carpetLen) << endl;
}
