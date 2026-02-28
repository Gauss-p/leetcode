#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        vector<vector<int>> f(2, vector<int>(2, 0));
        for (int i : nums){
            int x = i%2;
            for (int y=0; y<2; y++){
                f[y][x] = f[x][y]+1;
                res = max(res, f[y][x]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.maximumLength(nums) << endl;
}
