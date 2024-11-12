#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int b = 0;
        int cnt0 = 0, cnt1 = 0;
        int res = 0;
        for (int e=0; e<n; e++){
            cnt0 += (s[e] == '0');
            cnt1 += (s[e] == '1');
            while (cnt0>k && cnt1>k){
                cnt0 -= (s[b] == '0');
                cnt1 -= (s[b] == '1');
                b++;
            }
            res += e-b+1;
            
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "10101";
    int k = 1;
    cout << sl.countKConstraintSubstrings(s, k) << endl;
}
