#include <iostream>
using namespace std;

class Solution {
private:
    int quickPow(int a, int b, int mod){
        int res = 1;
        while (b){
            if (b&1){
                res = (1ll*res*a)%mod;
            }
            a = (1ll*a*a)%mod;
            b >>= 1;
        }
        return res;
    }
public:
    int numberOfSets(int n, int k) {
        int modNum = 1e9+7;
        int a = n+k-1, b = 2*k;
        long long up = 1, down = 1;
        for (int i=a-b+1; i<=a; i++){
            up = (up*i)%modNum;
        }
        for (int i=1; i<=b; i++){
            down = (down*i)%modNum;
        }
        return (up*quickPow(down, modNum-2, modNum))%modNum;
    }
};

int main(){
    Solution s;
    int n = 30, k = 7;
    cout << s.numberOfSets(n, k) << endl;
}
