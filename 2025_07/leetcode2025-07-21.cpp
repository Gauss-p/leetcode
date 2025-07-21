#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        s += '.';
        int n = s.size();
        int last = 0;
        string res;
        for (int i=1; i<n; i++){
            if (s[i-1] != s[i]){
                int cur = i-last;
                res += string(min(cur, 2), s[last]);
                last = i;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "leeetcode";
    cout << sl.makeFancyString(s) << endl;
}
