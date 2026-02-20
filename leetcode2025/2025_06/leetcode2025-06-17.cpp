#include <iostream>
#include <vector>
using namespace std;

const int maxNum=100001, modNum=1000000007;
vector<long long> Fact(maxNum, 0), InvFact(maxNum, 0);

class Solution {
    long long quick_pow(long long a, long long b){
        long long res = 1;
        while (b>0){
            if (b&1){
                res = (res*a)%modNum;
            }
            a = (a*a)%modNum;
            b >>= 1;
        }
        return res;
    }

    void init(){
        Fact[0] = 1;
        for (int i=1; i<maxNum; i++){
            Fact[i] = (Fact[i-1]*i)%modNum;
        }

        InvFact[maxNum-1] = quick_pow(Fact[maxNum-1], modNum-2);
        for (int i=maxNum-1; i>=1; i--){
            InvFact[i-1] = InvFact[i]*i%modNum;
        }
    }

    long long comb(int n, int m){
        return (Fact[n]*InvFact[m])%modNum*InvFact[n-m]%modNum;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n-1, k)*m%modNum *quick_pow(m-1, n-k-1)%modNum;
    }
};

int main(){
    Solution s;
    int n = 3, m = 2, k = 1;
    cout << s.countGoodArrays(n, m, k) << endl;
}
