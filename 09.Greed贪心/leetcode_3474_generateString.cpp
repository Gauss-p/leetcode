#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n+m-1, 'a');
        for (int i=0; i<n; i++){
            if (str1[i] == 'T'){
                res = res.substr(0, i)+str2+res.substr(i+m, n+m-1-(i+m));
            }
        }
        for (int i=0; i<n; i++){
            if (str1[i] == 'T' && res.substr(i, m)!=str2){
                return "";
            }
        }
        for (int i=0; i<n; i++){
            if (str1[i] == 'F' && res.substr(i, m)==str2){
                bool flag = false;
                for (int j=i+m-1; j>=i; j--){
                    if (res[j] == 'a'){
                        res[j] = 'b';
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    return "";
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string s1 = "TFTF", s2 = "ab";
    cout << s.generateString(s1, s2) << endl;
}
