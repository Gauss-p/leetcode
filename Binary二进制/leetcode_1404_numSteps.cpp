#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        while (s.size() > 1){
            if (s[s.size()-1] == '0'){
                s = s.substr(0, s.size()-1);
            }
            else{
                int indx = s.size()-1;
                while (indx >= 0 && s[indx] == '1'){
                    s[indx] = '0';
                    indx--;
                }
                if (indx >= 0){
                    s[indx] = '1';
                }
                else{
                    s = "1"+s;
                }
            }
            res++;
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "1101";
    cout << sl.numSteps(s) << endl;
}
