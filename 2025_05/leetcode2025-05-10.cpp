#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=0, s2=0, z1=0, z2=0;
        for (int i : nums1){
            s1 += i;
            z1 += (i==0);
        }
        for (int i : nums2){
            s2 += i;
            z2 += (i==0);
        }
        long long target = max(s1+z1, s2+z2);
        if ((target>s1 && z1==0) || (target>s2 && z2==0)){
            return -1;
        }
        return target;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {3,2,0,1,0};
    vector<int> nums2 = {6,5,0};
    cout << s.minSum(nums1, nums2) << endl;
}
