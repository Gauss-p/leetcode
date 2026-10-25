#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        int n = s.size();
        for (int i=1; i<n; i++){
            res += abs(s[i]-s[i-1]);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "hello";
    cout << sl.scoreOfString(s) << endl;
}
