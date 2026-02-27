#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while ((n&1) != ((n>>1)&1)){
            n >>= 1;
        }
        return n==0;
    }
};

int main(){
    Solution s;
    int n = 5;
    cout << s.hasAlternatingBits(n) << endl;
}
