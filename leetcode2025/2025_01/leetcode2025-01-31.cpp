#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string res;
        int indx = 0;
        for (int i=0; i<s.size(); i+=k){
            string tmp = s.substr(i, k);
            if (indx&1){
                res += tmp;
            }
            else{
                for (int j=tmp.size()-1; j>=0; j--) res += tmp[j];
            }
            indx++;
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "abcdefg";
    int k = 2;
    cout << sl.reverseStr(s, k) << endl;
}
