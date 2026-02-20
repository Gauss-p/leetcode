#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int mod_num = 1e9+7;
        int res = 2;
        sort(ranges.begin(), ranges.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        int max_right = ranges[0][1];
        for (auto &r : ranges){
            if (r[0] <= max_right){
                max_right = max(max_right, r[1]);
            }
            else{
                max_right = r[1];
                res = (res%mod_num)*2;
                res %= mod_num;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ranges = {{1,3},{10,20},{2,5},{4,8}};
    cout << s.countWays(ranges);
}
