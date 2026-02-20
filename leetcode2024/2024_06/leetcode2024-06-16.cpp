#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() == b.size()){
            if (a != b) return a.size();
            return -1;
        }
        return max(a.size(), b.size());
    }
};

int main(){
    Solution s;
    string a = "aba", b = "cdc";
    cout << s.findLUSlength(a, b) << endl;
}
