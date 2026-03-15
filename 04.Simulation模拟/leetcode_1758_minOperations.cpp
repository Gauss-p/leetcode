#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int res1 = 0, res2 = 0;
        int cur = 0;
        for (auto& c : s){
            if (cur == (c-'0')){
                res2++;
            }
            else{
                res1++;
            }
            cur ^= 1;
        }
        return min(res1, res2);
    }
};

int main(){
    Solution sl;
    string s = "10";
    cout << sl.minOperations(s) << endl;
}
