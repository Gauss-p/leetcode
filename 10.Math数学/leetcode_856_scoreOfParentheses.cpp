#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        unordered_map<int, int> val = {{'(', 1}, {')', -1}};
        int res = 0, cnt = 0;
        for (int i=0; i<s.size(); i++){
            if (i > 0 && s[i-1] == '(' && s[i] == ')'){
                res += pow(2, cnt-1);
            }
            cnt += val[s[i]];
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "(())";
    cout << sl.scoreOfParentheses(s) << endl;
}
