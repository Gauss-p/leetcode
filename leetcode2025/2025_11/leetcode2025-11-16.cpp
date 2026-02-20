#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        int modNum = 1e9+7;
        s += '0';
        int n = s.size();
        int last = 0;
        int res = 0;
        for (int i=1; i<n; i++){
            if (s[i-1] != s[i]){
                if (s[i-1] == '1'){
                    int curLength = i-last;
                    res = (res+1ll*(1+curLength)*curLength/2)%modNum;
                }
                last = i;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "0110111";
    cout << sl.numSub(s) << endl;
}
