#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        // 一种方案是两个字符串拼接到一起，然后用滑动窗口统计最短并且包含至少k个abc的字符串的长度，另外一种是直接在原字符串中遍历，用滑动窗口统计取走几个abc后剩下的中间部分的长度，求出该窗口的最大长度，返回总长度减去该最大长度即可
        // if (k == 0) return 0;
        // int n = s.size();
        // vector<int> cnt(3, 0);
        // int res = 0;
        // for (int i=0; i<n; i++){
        //     cnt[s[i]-'a']++;
        //     if (res == 0 && cnt[0] >= k && cnt[1] >= k && cnt[2] >= k){
        //         res = i+1;
        //     }
        // }
        // if (cnt[0] < k || cnt[1] < k || cnt[2] < k){
        //     return -1;
        // }

        // string double_str = s+s;
        // cnt[s[0]-'a']--;
        // int r = n-1;
        // for (int l=1; l<n; l++){
        //     while (r<2*n-1 && (cnt[0] < k || cnt[1] < k || cnt[2] < k)){
        //         r++;
        //         cnt[double_str[r]-'a']++;
        //     }
        //     if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k){
        //         res = min(res, r-l+1);
        //     }
        //     cnt[double_str[l]-'a']--;
        // }
        // return res;
        // -------------------------------------------------------------------
        vector<int> total_cnt(3, 0);
        for (auto c : s){
            total_cnt[c-'a']++;
        }
        if (total_cnt[0] < k || total_cnt[1] < k || total_cnt[2] < k){
            return -1;
        }
        int r = 0, l = 0;
        int mx = 0;
        int n = s.size();
        vector<int> cnt(3, 0);
        while (r < n){
            cnt[s[r] - 'a']++;
            while (total_cnt[0]-cnt[0] < k || total_cnt[1]-cnt[1] < k || total_cnt[2]-cnt[2] < k){
                // 如果去掉中间的剩余部分后余下的左右两边中不能满足abc的个数都大于等于k，就减小中间部分的范围，右移左端点
                cnt[s[l]-'a']--;
                l++;
            }
            mx = max(mx, r-l+1);
            r++;
        }
        return n-mx;
    }
};

int main(){
    Solution so;
    string s = "aabaaaacaabc";
    int k = 2;
    cout << so.takeCharacters(s, k) << endl;
}
