#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        // 也可以这样想，如果n是4的幂，那么它的二进制肯定符合以下条件：1.只有一个1；2.唯一的1在偶数位上。因此我们可以构造出所有1在奇数位上的情况，也就是数字：10101010...10101010，然后如果n和这个数字相与是0，就说明n的唯一一个1在偶数位上。我们可以发现，如果构造32个位置，那么这里面就是由8个1010组成的，而1010在二进制中等于A在十六进制中，所以可以写成8个a
        return n>0 && (n&(-n))==n && (n&(0xaaaaaaaa))==0;
    }
};

int main(){
    Solution s;
    int n = 16;
    cout << s.isPowerOfFour(n) << endl;
}
