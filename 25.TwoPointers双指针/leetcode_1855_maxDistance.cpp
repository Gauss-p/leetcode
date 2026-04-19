#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0;
        int res = 0;
        for (int i2=0; i2<n2; i2++){
            while (i1<n1 && nums1[i1] > nums2[i2]){
                i1++;
            }
            if (i1 == n1){
                break;
            }
            if (i1 <= i2){
                res = max(res, i2-i1);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};
    cout << s.maxDistance(nums1, nums2) << endl;
}
