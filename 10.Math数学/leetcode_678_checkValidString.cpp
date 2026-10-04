#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // [mn,mx]表示未配对左括号的数量取值范围，故最终只需判断mn是否为0即可知道是否可以将所有左括号配对完，对于右括号，则需在循环过程中保证mx始终大于等于0
        int mn = 0, mx = 0;
        for (char& c : s){
            if (c == '('){
                mn++;
                mx++;
            }
            else if (c == ')'){
                mn--;
                mx--;
                if (mx < 0){
                    return false;
                }
            }
            else{
                mn--;
                mx++;
            }
            mn = max(mn, 0);
        }
        return mn == 0;
    }
};

int main(){
    Solution sl;
    string s = "(*)";
    cout << sl.checkValidString(s) << endl;
}
