#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i=0; i<n; i++){
            res.push_back(nums[nums[i]]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,2,1,5,3,4};
    vector<int> res = s.buildArray(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
