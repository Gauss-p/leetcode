#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n&1){
            return false;
        }
        int mn=0, mx=0;
        for (int i=0; i<n; i++){
            if (locked[i] == '1'){
                if (s[i] == '('){
                    mn++;
                    mx++;
                }
                else{
                    mn--;
                    if (mn < 0){
                        mn = 1;
                    }
                    mx--;
                    if (mx < 0){
                        return false;
                    }
                }
            }
            else{
                mn--;
                if (mn < 0){
                    mn = 1;
                }
                mx++;
            }
        }
        return mn==0;
    }
};

int main(){
    Solution sl;
    string s = "))()))";
    string locked = "010100";
    cout << sl.canBeValid(s, locked) << endl;
}
