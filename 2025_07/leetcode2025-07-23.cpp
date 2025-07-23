#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (y > x){
            swap(a, b);
            swap(x, y);
        }
        s += '.';
        int cntA = 0, cntB = 0;
        int res = 0;
        for (auto& c : s){
            if (c == a){
                cntA++;
            }
            else if (c == b){
                if (cntA > 0){
                    cntA--;
                    res += x;
                }
                else{
                    cntB++;
                }
            }
            else{
                res += min(cntA, cntB)*y;
                cntA = 0;
                cntB = 0;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "cdbcbbaaabab";
    int x = 4, y = 5;
    cout << sl.maximumGain(s, x, y) << endl;
}
