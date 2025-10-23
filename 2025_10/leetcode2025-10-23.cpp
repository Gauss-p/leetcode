#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        for (int i=0; i<n-2; i++){
            for (int j=0; j<s.size()-1; j++){
                s[j] = '0'+((s[j]-'0')+(s[j+1]-'0'))%10;
            }
            s = s.substr(0, s.size()-1);
        }
        return s[0]==s[1];
    }
};

int main(){
    Solution sl;
    string s = "3902";
    cout << sl.hasSameDigits(s) << endl;
}
