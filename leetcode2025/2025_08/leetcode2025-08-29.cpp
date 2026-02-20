#include <iostream>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res = 0;
        int n_odd = (n+1)/2, n_even = n-n_odd;
        int m_odd = (m+1)/2, m_even = m-m_odd;
        res = 1ll*n_odd*m_even + 1ll*n_even*m_odd;
        return res;
    }
};

int main(){
    Solution s;
    int n=3, m=2;
    cout << s.flowerGame(n, m) << endl;
}
