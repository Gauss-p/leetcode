#include <iostream>
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int res = 0;
        for (int i=1; i<min(n+1, k/2+1); i++){
            res += i;
        }
        for (int i=k; i<k+max(0, n-k/2); i++){
            res += i;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n=5, k=4;
    cout << s.minimumSum(n, k) << endl;
}
