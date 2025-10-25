#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int t=n/7, m=n%7;
        return 7*(t*t+t*7)/2 + m*t + (m+m*m)/2;
    }
};

int main(){
    Solution s;
    int n = 4;
    cout << s.totalMoney(n) << endl;
}
