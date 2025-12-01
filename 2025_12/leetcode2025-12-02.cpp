#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> cnt;
        for (auto& p : points){
            cnt[p[1]]++;
        }

        int modNum = 1e9+7;
        long long res = 0;
        long long tot = 0;
        for (auto& kv : cnt){
            long long cur = 1ll*(kv.second-1)*kv.second/2;
            res = (res+tot*cur)%modNum;
            tot = (tot+cur)%modNum;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    cout << s.countTrapezoids(points) << endl;
}
