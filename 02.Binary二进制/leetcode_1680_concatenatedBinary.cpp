#include <iostream>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int pos = 0;
        int modNum = 1e9+7;
        for (int i=1; i<=n; i++){
            if ((i&(-i)) == i){
                pos++;
            }
            res = (res<<pos | i)%modNum;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    cout << s.concatenatedBinary(n) << endl;
}
