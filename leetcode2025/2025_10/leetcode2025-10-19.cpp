#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> odd, even;
        for (int i=0; i<n; i++){
            if (i&1){
                odd.push_back(s[i]-'0');
            }
            else{
                even.push_back(s[i]-'0');
            }
        }

        string res(n, '9');
        for (int i=0; i<=9*a; i+=a){
            string curOdd;
            for (int indx=0; indx<odd.size(); indx++){
                curOdd += ('0'+(odd[indx]+i)%10);
            }
            int upper = (b&1==1 ? 9*a : 0);
            for (int j=0; j<=upper; j+=a){
                string curEven;
                for (int indx=0; indx<even.size(); indx++){
                    curEven += ('0'+(even[indx]+j)%10);
                }
                string tot;
                for (int indx=0; indx<n; indx++){
                    if (indx&1){
                        tot += curOdd[indx/2];
                    }
                    else{
                        tot += curEven[indx/2];
                    }
                }

                string mode = tot.substr(n-b, b)+tot.substr(0, n-b);
                string curAns = tot;
                while (mode != tot){
                    curAns = min(curAns, mode);
                    mode = mode.substr(n-b, b)+mode.substr(0, n-b);
                }
                res = min(res, curAns);
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "5525";
    int a=9, b=2;
    cout << sl.findLexSmallestString(s, a, b) << endl;
}
