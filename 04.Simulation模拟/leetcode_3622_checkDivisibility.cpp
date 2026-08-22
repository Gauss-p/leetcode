#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0, m=1, origin=n;
        while (n){s=s+(n%10); m=m*(n%10); n=n/10;}
        return origin%(s+m)==0;
    }
};

int main(){
    Solution s;
    int n = 23;
    cout << s.checkDivisibility(n) << endl;
}
