#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int n;
    bool myCheck(int op, string s){
        int i=0, j=n-1;
        int tmp = 0;
        while (i<j){
            if (s[i]!=s[j]){
                if (tmp==1) return false;
                tmp = 1;
                if (op==0){
                    i++;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        n = s.size();
        return myCheck(0, s) | myCheck(1, s);
    }
};

int main(){
    Solution sl;
    string s = "abc";
    cout << sl.validPalindrome(s) << endl;
}
