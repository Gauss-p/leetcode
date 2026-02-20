#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (nums1[i]%(nums2[j]*k) == 0){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,3,4}, nums2 = {1,3,4};
    int k = 1;
    cout << s.numberOfPairs(nums1, nums2, k) << endl;
}
