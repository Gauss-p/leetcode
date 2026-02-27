#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()){
            swap(a, b);
        }
        int m = a.size(), n = b.size();
        int need = 0;
        string res;
        for (int i=1; i<=m; i++){
            int cur = (a[m-i]-'0')+need;
            if (i <= n){
                cur += (b[n-i]-'0');
            }
            string x = to_string(cur&1);
            if (cur <= 1){
                res = x+res;
                need = 0;
            }
            else{
                res = x+res;
                need = 1;
            }
        }
        if (need){
            res = '1'+res;
        }
        return res;
    }
};

int main(){
    Solution s;
    string a = "11", b = "1";
    cout << s.addBinary(a, b) << endl;
}
