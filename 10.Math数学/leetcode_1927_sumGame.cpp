#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        string left = num.substr(0, n/2), right = num.substr(n/2, n/2);
        int l = count(left.begin(), left.end(), '?');
        int r = count(right.begin(), right.end(), '?');
        if ((l+r)&1){
            return true;
        }
        float ls = 0, rs = 0;
        for (auto& i : left) ls += (i=='?' ? 4.5 : i-'0');
        for (auto& i : right) rs += (i=='?' ? 4.5 : i-'0');
        if (ls == rs){
            return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string num = "25??";
    cout << s.sumGame(num) << endl;
}
