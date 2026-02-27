#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int maxBits = 33;
        vector<int> isPrime(maxBits, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (int i=2; i<maxBits; i++){
            if (isPrime[i] == 0) continue;
            for (int j=2*i; j<maxBits; j+=i){
                isPrime[j] = 0;
            }
        }

        int res = 0;
        for (int i=left; i<=right; i++){
            res += isPrime[__builtin_popcount(i)];
        }
        return res;
    }
};

int main(){
    Solution s;
    int left = 6, right = 10;
    cout << s.countPrimeSetBits(left, right) << endl;
}
