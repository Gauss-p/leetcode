#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> cnt;
        vector<int> nums;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int a = grid[i][j];
                nums.push_back(a);
                cnt[a%x] = 1;
                if (cnt.size() == 2){
                    return -1;
                }
            }
        }
        sort(nums.begin(), nums.end());
        int target = nums[nums.size()/2];
        int res = 0;
        for (int i : nums){
            res += abs(i-target);
        }
        return res/x;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;
    cout << s.minOperations(grid, x) << endl;
}
