#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> mn(n+1, INT_MAX), mx(n+1, 0);
        for (int i=1; i<=n; i++){
            mx[i] = max(mx[i-1], nums[i-1]);
            mn[n-i] = min(mn[n-i+1], nums[n-i]);
        }

        int res = 0;
        for (int i=1; i<n-1; i++){
            if (nums[i] > mx[i] && nums[i] < mn[i+1]){
                res += 2;
            }
            else if (nums[i] > nums[i-1] && nums[i] < nums[i+1]){
                res += 1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.sumOfBeauties(nums) << endl;
}
