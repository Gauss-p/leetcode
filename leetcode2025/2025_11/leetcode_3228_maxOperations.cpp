#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ones = (s[0]=='1'), res = 0;
        for (int i=1; i<n; i++){
            ones += (s[i]=='1');
            if (s[i-1] == '1' && s[i] == '0'){
                res += ones;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "1001101";
    cout << sl.maxOperations(s) << endl;
}
