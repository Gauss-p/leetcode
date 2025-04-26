#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minKPos = -1, maxKPos = -1, notBelong = -1;
        long long res = 0;
        for (int i=0; i<n; i++){
            if (nums[i] == minK){
                minKPos = i;
            }
            if (nums[i] == maxK){
                maxKPos = i;
            }
            if (nums[i]<minK || nums[i]>maxK){
                notBelong = i;
            }
            if (minKPos!=-1 && maxKPos!=-1 && notBelong<min(minKPos, maxKPos)){
                res += min(minKPos, maxKPos)-notBelong;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;
    cout << s.countSubarrays(nums, minK, maxK) << endl;
}
