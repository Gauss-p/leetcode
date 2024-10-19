#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        bool flag = false;
        for (int i=0; i<n; i++){
            if (flag == false && nums[i] == 0){
                // for (int j=i; j<n; j++){
                //     nums[j] = 1-nums[j];
                // }
                flag = true;
                res++;
            }
            if (flag == true && nums[i] == 1){
                flag = false;
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,1,0,1};
    cout << s.minOperations(nums) << endl;
}
