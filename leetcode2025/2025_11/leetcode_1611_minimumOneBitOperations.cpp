#include <iostream>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0){
            return 0;
        }
        int k = 32-__builtin_clz(n);
        return (1<<k)-1 - minimumOneBitOperations(n-(1<<(k-1)));
    }
};

int main(){
    Solution s;
    int n = 3;
    cout << s.minimumOneBitOperations(n) << endl;
}
