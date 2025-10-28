#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        return (1<<(32-__builtin_clz(n)))-1;
    }
};

int main(){
    Solution s;
    int n = 5;
    cout << s.smallestNumber(n) << endl;
}
