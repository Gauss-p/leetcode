#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        unordered_map<int, int> val = {{'(', 1}, {')', -1}};
        int cnt = 0;
        string res;
        for (auto& i : s){
            cnt += val[i];
            if ((i=='(' && cnt==1) || (i==')' && cnt==0)){
                continue;
            }
            res += i;
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "(()())(())";
    cout << sl.removeOuterParentheses(s) << endl;
}
