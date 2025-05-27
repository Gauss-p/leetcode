#include <iostream>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (1+n)*n/2 - (m+(n/m)*m)*(n/m);
    }
};

int main(){
    Solution s;
    int n = 10, m = 3;
    cout << s.differenceOfSums(n, m) << endl;
}
