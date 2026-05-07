#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n+1, 0);
        for (int i=0; i<n; i++){
            preMax[i+1] = max(preMax[i], nums[i]);
        }
        vector<int> res(n, 0);
        res[n-1] = preMax[n];
        int sufMin = nums[n-1];
        for (int i=n-2; i>=0; i--){
            if (preMax[i+1] <= sufMin){
                res[i] = preMax[i+1];
            }
            else{
                res[i] = res[i+1];
            }
            sufMin = min(sufMin, nums[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3};
    vector<int> res = s.maxValue(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
