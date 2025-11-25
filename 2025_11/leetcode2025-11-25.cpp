#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        int cur = 1%k, tot = 1%k, length = 1;
        while (tot != 0){
            cur = (cur*10)%k;
            tot = (tot+cur)%k;
            length++;
        }
        return length;
    }
};

int main(){
    Solution s;
    int k = 3;
    cout << s.smallestRepunitDivByK(k) << endl;
}
