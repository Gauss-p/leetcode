#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == target){
                res = min(res, abs(i-start));
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    int target = 5, start = 3;
    cout << s.getMinDistance(nums, target, start) << endl;
}
