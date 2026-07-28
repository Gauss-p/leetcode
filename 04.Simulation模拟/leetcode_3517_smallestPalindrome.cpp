#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string left = s.substr(0, n/2);
        sort(left.begin(), left.end());
        left += (n%2 ? string(1, s[n/2]) : "");
        for (int i=n/2-1; i>=0; i--){
            left += left[i];
        }
        return left;
    }
};

int main(){
    Solution sl;
    string s = "baab";
    cout << sl.smallestPalindrome(s) << endl;
}
