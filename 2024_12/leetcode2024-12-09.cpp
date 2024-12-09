#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string c) {
        return !(((c[0] - 'a') + (c[1] - '0')) % 2);
    };
};

int main(){
    Solution s;
    string c = "a1";
    cout << s.squareIsWhite(c) << endl;
}
