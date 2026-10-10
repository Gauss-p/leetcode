#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> cnt(100001, 0);
        for (int i=0; i<nums1.size(); i++){
            cnt[abs(nums1[i]-nums2[i])]++;
        }
        
        int k = k1+k2;
        for (int i=cnt.size()-1; i>=1; i--){
            int change = min(cnt[i], k);
            cnt[i] -= change;
            k -= change;
            cnt[i-1] += change;
        }
        
        long long res = 0;
        for (int i=0; i<cnt.size(); i++){
            res += 1ll*cnt[i]*i*i;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,4,10,12}, nums2 = {5,8,6,9};
    int k1 = 1, k2 = 1;
    cout << s.minSumSquareDiff(nums1, nums2, k1, k2) << endl;
}
