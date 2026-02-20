#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return nums2[0]-nums1[0];
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2,6,4};
    vector<int> nums2 = {9,7,5};
    cout << s.addedInteger(nums1,nums2) << endl;
}
