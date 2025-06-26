#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        long long cnt = 0, v = 0;
        for (int i=n-1; i>=0; i--){
            if (s[i] == '0'){
                cnt++;
            }
            else{
                if (cnt<30){
                    // 这里是为了防止左移时超出longlong限制
                    // 而30是因为题目中最大数字1e9的二进制位数正好是2+30位，前面是0b需要占两位，所以正好是30位数字
                    v |= (1ll<<cnt);
                    if (v<=k){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main(){
    Solution sl;
    string s = "1001010";
    int k = 5;
    cout << sl.longestSubsequence(s, k) << endl;
}
