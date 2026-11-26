#include <iostream>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int tmp = 10;
        int cnt = 0;
        while (n>=tmp){
            n -= tmp;
            tmp--;
            cnt++;
        }
        if (cnt&1){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    int n = 12;
    cout << s.canAliceWin(n) << endl;
}
