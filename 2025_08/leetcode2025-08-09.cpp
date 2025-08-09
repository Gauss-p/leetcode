#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n==0 ? false : (long long)n==((long long)n&(-(long long)n));
    }
};

int main(){
    Solution s;
    int n = 1;
    cout << s.isPowerOfTwo(n) << endl;
}
