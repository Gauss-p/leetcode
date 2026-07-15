#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sO = (1+2*n-1)*n/2;
        int sE = (2+2*n)*n/2;
        return __gcd(sO, sE);
    }
};

int main(){
    Solution s;
    int n = 4;
    cout << s.gcdOfOddEvenSums(n) << endl;
}
