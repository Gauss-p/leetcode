#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cnt = 0;
        for (auto& c : s){
            cnt += (c=='(' ? 1 : (c==')' ? -1 : 0));
            res = max(res, cnt);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "()(())((()))";
    cout << sl.maxDepth(s) << endl;
}
