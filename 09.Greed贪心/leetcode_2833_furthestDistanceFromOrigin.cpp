#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0, s = 0;
        for (auto& c : moves){
            r += (c=='R');
            l += (c=='L');
            s += (c=='_');
        }
        return abs(l-r)+s;
    }
};

int main(){
    Solution s;
    string moves = "L_RL__R";
    cout << s.furthestDistanceFromOrigin(moves) << endl;
}
