#include <iostream>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1 ? 1.0 : 0.5;
    }
};

int main(){
    int n = 5;
    Solution s;
    cout << s.nthPersonGetsNthSeat(n);
}
