#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> mp1, mp2;
        int mx = 0;
        for (auto i : nums1){
            mx = max(mx, i);
            mp1[i]++;
        }
        for (auto i : nums2){
            mp2[i]++;
        }
        long long res = 0;
        for (auto &kv : mp2){
            int tmp = (kv.first)*k, space = (kv.first)*k;
            while (tmp <= mx){
                res += 1ll*mp1[tmp]*kv.second;
                tmp += space;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {1,3,4};
    Solution s;
    int k = 1;
    cout << s.numberOfPairs(nums1, nums2, k) << endl;
}
