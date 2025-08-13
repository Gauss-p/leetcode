#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int pows = 0, origin = n;
        while (n>=3){
            n /= 3;
            pows++;
        }
        return pow(3, pows)==origin;
    }
};

int main(){
    Solution s;
    int n = 27;
    cout << s.isPowerOfThree(n) << endl;
}
