#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int mx = 100001;
vector<bool> res;
int cnt = [](){
    res.resize(mx, false);
    for (int i=1; i<mx; i++){
        for (int j=1; j<=(int)sqrt(i); j++){
            res[i] = (res[i] | (!res[i-j*j]));
            if (j*j == i){
                res[i] = true;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    bool winnerSquareGame(int n) {
        return res[n];
    }
};

int main(){
    Solution s;
    int n = 2;
    cout << s.winnerSquareGame(n) << endl;
}
