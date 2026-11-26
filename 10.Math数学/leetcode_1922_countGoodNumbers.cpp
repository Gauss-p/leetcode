#include <iostream>
using namespace std;

class Solution {
private:
    long long myPow(long long a, long long b, int mod){
        long long res = 1;
        while (b){
            if (b&1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            b >>= 1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        return myPow(5, (n+1)/2, (int)1e9+7)*myPow(4, n-(n+1)/2, (int)1e9+7)%((int)1e9+7);
    }
};

int main(){
    Solution s;
    int n = 50;
    cout << s.countGoodNumbers(n) << endl;
}
