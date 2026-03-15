#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        s += '0';
        int res = 0;
        for (int i=0; i<s.size()-1; i++){
            if (s[i] == '1' && s[i+1] == '0'){
                res++;
            }
        }
        return res<=1;
    }
};

int main(){
    Solution sl;
    string s = "1001";
    cout << sl.checkOnesSegment(s) << endl;
}
