#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        for (auto i : nums1){
            mp1[i]++;
        }
        int res = INT_MAX;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        for (int i=0; i<3; i++){
            int tmp_sub = nums2[0]-nums1[i];
            unordered_map<int, int> mp2;
            for (auto i : nums2){
                mp2[i-tmp_sub]++;
            }
            bool flag = true;
            for (auto &kv : mp2){
                int x = kv.first;
                if (!mp1.count(x) || mp1[x] < mp2[x]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                res = min(res, tmp_sub);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {7,6,2,7,8};
    vector<int> nums2 = {7,5,6};
    cout << s.minimumAddedInteger(nums1, nums2) << endl;
}
