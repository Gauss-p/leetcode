#include <iostream>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long cur = 1000;
        while (cur <= n){
            res += n-cur+1;
            cur *= 1000;
        }
        return res;
    }
};

int main(){
    Solution s;
    long long n = 1002;
    cout << s.countCommas(n) << endl;
}
