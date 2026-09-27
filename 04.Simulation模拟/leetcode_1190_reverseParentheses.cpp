#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int tot = count(s.begin(), s.end(), ')');
        while (tot){
            int r = find(s.begin(), s.end(), ')')-s.begin();
            int l = r-1;
            string cur;
            while (s[l] != '('){
                cur += s[l];
                l--;
            }
            s = s.substr(0, l)+cur+s.substr(r+1);
            tot--;
        }
        return s;
    }
};

int main(){
    Solution sl;
    string s = "(u(love)i)";
    cout << sl.reverseParentheses(s) << endl;
}
