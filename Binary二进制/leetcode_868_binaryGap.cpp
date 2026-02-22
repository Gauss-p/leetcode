#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int i = 0;
        int res = 0;
        while (n){
            if (n&1){
                if (last >= 0){
                    res = max(res, i-last);
                }
                last = i;
            }
            n >>= 1;
            i++;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 22;
    cout << s.binaryGap(n) << endl;
}
