#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        return ((c1[0]-'a')+(c1[1]-'0'))%2 == ((c2[0]-'a')+(c2[1]-'0'))%2;
    }
};

int main(){
    Solution s;
    string c1 = "a1", c2 = "c3";
    cout << s.checkTwoChessboards(c1, c2) << endl;
}
