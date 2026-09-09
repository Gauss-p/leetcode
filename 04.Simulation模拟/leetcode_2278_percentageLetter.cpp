#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size(), res = 0;
        for (auto& c : s){
            if (c == letter){
                res += 100;
            }
        }
        return res/n;
    }
};

int main(){
    Solution sl;
    string s = "foobar";
    char letter = 'o';
    cout << sl.percentageLetter(s, letter) << endl;
}
