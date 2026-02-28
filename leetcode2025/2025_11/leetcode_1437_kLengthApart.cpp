#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int last = -1;
        for (int i=0; i<n; i++){
            if (nums[i]){
                if (last==-1){
                    last = i;
                    continue;
                }
                if (i-last-1 < k){
                    return false;
                }
                last = i;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;
    cout << s.kLengthApart(nums, k) << endl;
}
