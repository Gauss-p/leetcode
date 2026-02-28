#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        bool flag = (s[0]=='9');
        string res;
        char first = 'a';
        for (char i : s){
            if (flag){
                if (i == '9'){
                    res += '9';
                }
                else{
                    if (first == 'a' || i == first){
                        first = i;
                        res += to_string(9-(i-'0'));
                    }
                    else{
                        res += '0';
                    }
                }
            }
            else{
                if (first == 'a' || i == first){
                    first = i;
                    res += '9';
                }
                else{
                    res += '0';
                }
            }
        }
        return stoi(res);
    }
};

int main(){
    Solution s;
    int num = 11891;
    cout << s.minMaxDifference(num) << endl;
}
