#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, zero = 0;
        for (auto &i : s){
            if (i == '1') one++;
            if (i == '0') zero++;
        }
        // string res;
        // while (--one){
            // res += '1';
        // }
        // while (zero--){
            // res += '0';
        // }
        // res += '1';
        return string(one-1, '1')+string(zero, '0')+'1';
    }
};

int main(){
    Solution sol;
    string s = "010";
    // string s = "0101";
    cout << sol.maximumOddBinaryNumber(s) << endl;
    return 0;
}
