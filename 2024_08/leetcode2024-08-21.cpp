#include <iostream>
using namespace std;

class Solution {
public:
    // long long price(int n, int x){
    //     long long res = 0;
    //     while (n > 0){
    //         res += (n>>(x-1))&1;
    //         n = n>>x;
    //     }
    //     return res;
    // }
    long long findMaximumNumber(long long k, int x) {
        // 假设第i位以前(也就是更高的位上)的所有位上，位数是x的倍数且填了1的位一共有pre1个，那么如果第i位填1，对于前面的位而言，从1到num-1的总价值就会多出pre1*2^i，因为前面的位已经定下来了，而如果第i位变成了1，从1到num-1的第i位以后的数字就会多出2^i种，比方说，如果将第2位的数字变成了1，那么从1到num-1的所有数字的后两位就会多出以下2^2=4种排列：00，01，10，11.
        // 而对于后面的位而言，因为第i位及以后的排列方式会有2^i种，所以可以知道，如果将1到num-1的最后i位单独列出来，其中有2^i种，同时每一位上统计都有2^(i-1)个1，而又因为i位及以后一共有i/x个需要计算的位，所以可以知道，1到num-1的总价值又会多出(i/x)*(2^(i-1))，所以每一次如果将第i位设置为1，1到num-1的总价值就会多出pre1*2^i+(i/x)*(2^(i-1))，只要计算总价值累加是否还小于等于k即可
        // 这个时候，我们需要计算i的起点。可以发现，如果数字取(k+1)*(2^x)时，就可以保证其价值最小都是k+1，因为是这样的，2^x转成二进制是1后面跟x个0，所以只要将k+1乘上这个数字，就可以保证至少价值有k+1
        long long ans = 0, pre1 = 0;
        int i = __lg((k+1)<<x)-1;
        for (; i>=0; i--){
            long long cnt = (1ll*pre1<<i)+(1ll*(i/x)<<i>>1);
            if (cnt <= k){
                k -= cnt;
                ans |= (1LL<<i);
                pre1 += (i+1)%x == 0;
            }
        }
        return ans-1;
        // long long ans = 0;
        // long long worth = 0;
        // while (worth <= k){
        //     ans++;
        //     worth += price(ans, x);
        // }
        // return ans-1;
    }
};

int main(){
    Solution s;
    long long k = 7;
    int x = 1;
    cout << s.findMaximumNumber(k, x) << endl;
}
