#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; i+=3){
            if (nums[i+2]-nums[i] > k){
                return {};
            }
            else{
                res.push_back({nums[i], nums[i+1], nums[i+2]});
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> res = s.divideArray(nums, k);
    for (auto i : res){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
