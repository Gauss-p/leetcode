#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int pos = n;
        vector<int> nextZero(n, n);
        for (int i=n-1; i>=0; i--){
            nextZero[i] = pos;
            if (s[i] == '0'){
                pos = i;
            }
        }

        int res = 0;
        for (int i=0; i<n; i++){
            int cnt0 = (s[i]=='0');
            int j = i;
            while (j<n && cnt0*cnt0<n){
                int cnt1 = (nextZero[j]-i)-cnt0;
                if (cnt1 >= cnt0*cnt0){
                    res += min(nextZero[j]-j, cnt1-cnt0*cnt0+1);
                }
                j = nextZero[j];
                cnt0++;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "00011";
    cout << sl.numberOfSubstrings(s) << endl;
}
