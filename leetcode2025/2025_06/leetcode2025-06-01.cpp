#include <iostream>
using namespace std;

class Solution {
private:
    long long comb_n_2(int x){
        if (x < 0){
            return 0;
        }
        return 1ll*x*(x-1)/2;
    }
public:
    long long distributeCandies(int n, int limit) {
        return comb_n_2(n+2)-3*comb_n_2(n-(limit+1)+2)+3*comb_n_2(n-2*(limit+1)+2)-comb_n_2(n-3*(limit+1)+2);
    }
};

int main(){
    Solution s;
    int n = 5, limit = 2;
    cout << s.distributeCandies(n, limit) << endl;
}
