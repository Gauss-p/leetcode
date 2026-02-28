#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n==1){
            return "";
        }
        for (int i=0; i<n/2; i++){
            if (palindrome[i]!='a'){
                return palindrome.substr(0,i)+'a'+palindrome.substr(i+1,n-i-1);
            }
        }
        return palindrome.substr(0,n-1)+'b';
    }
};

int main(){
    Solution s;
    string palindrome = "abccba";
    cout << s.breakPalindrome(palindrome) << endl;
}
