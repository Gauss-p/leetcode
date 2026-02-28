#include <iostream>
using namespace std;

class Solution {
private:
    int cnt(long long x){
        int res = 0;
        while (x){
            if (x&1){
                res++;
            }
            x >>= 1;
        }
        return res;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 0;
        while (true){
            long long x = num1 - 1ll*k*num2;
            if (k>x){
                return -1;
            }
            if (k>=cnt(x)){
                return k;
            }
            k++;
        }
    }
};

int main(){
    Solution s;
    int num1 = 3, num2 = -2;
    cout << s.makeTheIntegerZero(num1, num2) << endl;
}
