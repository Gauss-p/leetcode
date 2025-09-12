#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        int cnt = 0;
        for (auto& c : s){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sl;
    string s = "leetcoder";
    cout << sl.doesAliceWin(s) << endl;
}
