#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int tmp1 = to_string(nums[i])[0]-'0';
            for (int j=i+1; j<n; j++){
                int tmp2 = to_string(nums[j]).back()-'0';
                if (gcd(tmp1, tmp2) == 1){
                    res++;
                }
            }
        }
        return res;
    }
    int maxVowels(string s, int k) {
        int cnt = 0;
        int n = s.size();
        int res = 0;
        // for (int i=0; i<n; i++){
        //     if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
        //         cnt++;
        //     }
        //     if (i < k-1) continue;
        //     res = max(res, cnt);
        //     if (s[i-k+1] == 'a' || s[i-k+1] == 'e' || s[i-k+1] == 'i' || s[i-k+1] == 'o' || s[i-k+1] == 'u'){
        //         cnt--;
        //     }
        // }
        for (int i=0; i<n; i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt++;
            }
            if (i == k-1) res = max(res, cnt);
            if (i <= k-1) continue;
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                cnt--;
            }
            res = max(res, cnt);
        }
        return res;
    }
};

int main(){
    Solution so;
    vector<int> nums = {2, 5, 1, 4};
    string s = "abcedfg";
    int k = 2;
    cout << so.countBeautifulPairs(nums) << endl;
    cout << so.maxVowels(s, k) << endl;
}
