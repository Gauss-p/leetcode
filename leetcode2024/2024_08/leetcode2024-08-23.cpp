#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pow(long long x, long long n, long long mod){
        // 快速幂算法
        long long res = 1%mod;
        for (; n; n/=2){
            if (n%2){
                res = res*x%mod;
            }
            x = x*x%mod;
        }
        return res;
    }

    long long sumE(long long k){
        // 这个函数用来计算0到k的bigNums幂次之和
        long long res = 0, n = 0, cnt1 = 0, sumI = 0;
        for (long long i=__lg(k+1); i; i--){
            // 计算新增的幂次的个数
            long long c = (cnt1 << i) + (i << (i-1));
            if (c <= k){
                // 填入1
                k -= c; // 每一次都将需要计算的k减去已经算出的c
                res += (sumI<<i)+((i*(i-1)/2)<<(i-1));// 其中第一项还不明白，第二项是从0到2^i中的幂次之和
                sumI += i; // 幂次和加上i
                cnt1++;
                n |= 1ll<<i;
            }
        }
        if (cnt1 <= k){
            // 处理最后一位
            k -= cnt1;
            res += sumI<<0;
            n |= 1;
        }
        while (k--){
            // 如果还有没算完的，就将n最后一位的幂次加入答案
            res += __builtin_ctzll(n);
            n &= n-1;
        }
        return res;
    }
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        // 定义res，对于每一组问题，只需要计算从0到to_i+1的幂次之和r以及从0到from_i的幂次之和l，答案就是2^(r-l)%mod_i
        vector<int> res;
        for (auto &q : queries){
            auto r = sumE(q[1]+1);
            auto l = sumE(q[0]);
            res.push_back(pow(2, r-l, q[2]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<long long>> queries = {{2,5,3},{7,7,4}};
    vector<int> res = s.findProductsOfElements(queries);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
