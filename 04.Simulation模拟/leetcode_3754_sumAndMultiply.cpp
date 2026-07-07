#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long newN = 0;
        long long tot = 0;
        for (auto& c : s){
            if (c != '0'){
                newN = newN*10+(c-'0');
                tot += (c-'0');
            }
        }
        return newN*tot;
    }
};

int main(){
    Solution s;
    int n = 10203004;
    cout << s.sumAndMultiply(n) << endl;
}
