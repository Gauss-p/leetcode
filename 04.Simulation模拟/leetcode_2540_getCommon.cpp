#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2;
        int res = INT_MAX;
        for (int i : nums1) cnt1[i]++;
        for (int i : nums2) cnt2[i]++;
        for (auto& kv : cnt1){
            if (cnt2[kv.first]){
                res = min(res, kv.first);
            }
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3}, nums2 = {2,4};
    cout << s.getCommon(nums1, nums2) << endl;
}
