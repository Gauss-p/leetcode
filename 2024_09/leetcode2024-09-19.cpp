#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 0, tmp_len = 1;
        int n = s.size();
        for (int i=1; i<n; i++){
            if (s[i]-s[i-1] == 1){
                tmp_len++;
            }
            else{
                res = max(res, tmp_len);
                tmp_len = 1;
            }
        }
        res = max(res, tmp_len);
        return res;
    }
};

int main(){
    Solution so;
    string s = "abacaba";
    cout << so.longestContinuousSubstring(s) << endl;
}
