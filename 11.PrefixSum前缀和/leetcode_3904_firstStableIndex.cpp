#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preMax(n+1, 0);
        vector<int> sufMin(n+1, INT_MAX);
        for (int i=0; i<n; i++){
            preMax[i+1] = max(preMax[i], nums[i]);
            sufMin[n-i-1] = min(sufMin[n-i], nums[n-i-1]);
        }
        for (int i=0; i<n; i++){
            if (preMax[i+1]-sufMin[i] <= k){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,0,1,4};
    int k = 3;
    cout << s.firstStableIndex(nums, k) << endl;
}
