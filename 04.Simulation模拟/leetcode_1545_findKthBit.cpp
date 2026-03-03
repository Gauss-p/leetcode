#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        k--;
        int length = (1<<n)-1;
        bool rev = false;
        for (int i=0; i<n-1; i++){
            int mid = length>>1;
            if (k > mid){
                k = mid*2-k;
                rev = !rev;
            }
            else if (k == mid){
                return rev ? '0' : '1';
            }
            length >>= 1;
        }
        return rev ? '1' : '0';
    }
};

int main(){
    Solution s;
    int n = 3, k = 1;
    cout << s.findKthBit(n, k) << endl;
}
