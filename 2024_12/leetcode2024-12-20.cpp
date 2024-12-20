#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int res = 0;
        for (int l=1; l<=n; l++){
            if (n % l != 0){
                continue;
            }
            string tmp = s.substr(0, l);
            sort(tmp.begin(), tmp.end());
            bool flag = true;
            for (int i=l; i<n; i+=l){
                string tmp2 = s.substr(i, l);
                sort(tmp2.begin(), tmp2.end());
                if (tmp != tmp2){
                    flag = false;
                    break;
                }
            }
            if (flag){
                res = l;
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "abba";
    cout << sl.minAnagramLength(s) << endl;
}
