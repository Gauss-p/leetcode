#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        string res;
        for (auto &i : s){
            if (i != 'i'){
                res += i;
            }
            else{
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s = "poiinter";
    cout << sol.finalString(s) << endl;
}
