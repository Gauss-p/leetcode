#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (auto& c : s){
            if (c == '*'){
                res = res.substr(0, res.size()-1);
            }
            else if (c == '#'){
                res += res;
            }
            else if (c == '%'){
                string cur = "";
                for (auto& i : res){
                    cur = i+cur;
                }
                res = cur;
            }
            else{
                res += c;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "a#b%*";
    cout << sl.processStr(s) << endl;
}
