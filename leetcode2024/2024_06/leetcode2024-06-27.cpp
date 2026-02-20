#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int indx = 0;
        while (indx < n && s[indx] == 'a') indx++;
        for (int i=indx; i<n; i++){
            if (s[i] == 'a') break;
            s[i] = s[i]-1;
        }
        if (indx == n){
            s[n-1] = 'z';
        }
        return s;
    }
};

int main(){
    Solution so;
    string s = "cbabc";
    cout << so.smallestString(s) << endl;
}
