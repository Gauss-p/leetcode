#include <iostream>
using namespace std;

class Solution {
private:
    bool check(int x){
        int half = 0, tot = 0, n = 0;
        int y = x;
        while (y){
            tot += (y%10);
            y /= 10;
            n++;
        }
        if (n&1){
            return false;
        }
        n /= 2;
        while (x && n){
            half += (x%10);
            x /= 10;
            n--;
        }
        return tot == half*2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i=low; i<=high; i++){
            if (check(i)){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int low = 1, high = 100;
    cout << s.countSymmetricIntegers(low, high) << endl;
}
