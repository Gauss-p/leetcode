#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        while (n){
            int cur = n%10;
            if (cur > mx1){
                mx2 = mx1;
                mx1 = cur;
            }
            else if (cur > mx2){
                mx2 = cur;
            }
            n = n/10;
        }
        return mx1*mx2;
    }
};

int main(){
    Solution s;
    int n = 31;
    cout << s.maxProduct(n) << endl;
}
