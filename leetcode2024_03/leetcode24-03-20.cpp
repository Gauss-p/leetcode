#include <iostream>
using namespace std;

class Solution {
public:
    long long mod_num = 1e9+7;
    int my_fast_power(long long n, int p){
        // p为位数，由于需要计算幂的数字二进制所有位置均为1，所以只需要逐个相乘即可
        // 因各个位置都是1，所以可以写成2^(p-1)+2^(p-2)+...+2^1+2^0的形式
        // 再根据幂的计算规则,就可以知道所求数为:
        // n^(2^(p-1))*n^(2^(p-2))*...*n^(2^1)*n^(2^0)
        n = n%mod_num;
        int res = 1;
        while (p--){
            res = (res*n)%mod_num;
            n = (n*n)%mod_num;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        if (p == 1) return 1;
        long long l = (1ll<<p)-1;
        long long res = my_fast_power(l-1, p-1)%mod_num;
        return (res%mod_num)*(l%mod_num)%mod_num;
    }
};

int main(){
    Solution s;
    int p = 36;
    cout << s.minNonZeroProduct(p) << endl;
}
