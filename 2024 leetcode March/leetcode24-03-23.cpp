#include <iostream>
using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        return n==1 ? 1 : n-1;
    }
};

int main(){
    Solution s;
    int n = 4;
    cout << s.distinctIntegers(n) << endl;
}
