#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int i=1; i<=n; i++){
            for (int j=i+1; j<=n; j++){
                int k_squared = i*i+j*j;
                int k = sqrt(k_squared);
                if (k*k==k_squared &&  k_squared <= n*n){
                    res += 1+(i!=j);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    cout << s.countTriples(n) << endl;
}
