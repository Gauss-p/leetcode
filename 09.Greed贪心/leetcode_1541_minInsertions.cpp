#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        s += '.';
        int n = s.size();
        int res = 0, last = 0, cnt = 0;
        for (int i=0; i<n; i++){
            if (s[i] != s[last]){
                int length = i-last;
                if (s[last] == '('){
                    cnt += length;
                }
                else{
                    res += (length&1);
                    cnt -= (length+(length&1))/2;
                    if (cnt < 0){
                        res += -cnt;
                        cnt = 0;
                    }
                }
                last = i;
            }
        }
        return res+cnt*2;
    }
};

int main(){
    Solution sl;
    string s = "(()))";
    cout << sl.minInsertions(s) << endl;
}
