#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        string cur = s;
        for (int i=0; i<s.size(); i++){
            cur = cur.substr(1)+cur[0];
            if (cur == goal){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sl;
    string s = "abcde", goal = "cdeab";
    cout << sl.rotateString(s, goal) << endl;
}
