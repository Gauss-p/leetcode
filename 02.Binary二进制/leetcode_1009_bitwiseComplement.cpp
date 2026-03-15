#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        return ((1<<(n==0 ? 1 : 32-__builtin_clz(n)))-1)^n;
    }
};

int main(){
    Solution s;
    int n = 5;
    cout << s.bitwiseComplement(n) << endl;
}
