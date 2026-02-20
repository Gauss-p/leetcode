#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 0;
        vector<vector<int>> f(k, vector<int>(k, 0));
        for (int i : nums){
            int x = i%k;
            for (int y=0; y<k; y++){
                f[y][x] = f[x][y] + 1;
                res = max(res, f[y][x]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,2,3,1,4};
    int k = 3;
    cout << s.maximumLength(nums, k) << endl;
}
