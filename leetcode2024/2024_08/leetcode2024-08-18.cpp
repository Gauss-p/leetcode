#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        for (int i=0; i<n-2; i++){
            if (s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L'){
                return false;
            }
        }
        int a = 0;
        for (auto i : s){
            if (i == 'A'){
                a++;
            }
        }
        if (a < 2){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    string st = "PPALLP";
    cout << s.checkRecord(st) << endl;
}
