#include <iostream>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        if ((n&k) != k) return -1;
        return __builtin_popcount(n^k);
        // -----------------------------------------------------------
        // bitset<20> bs1(n), bs2(k);
        // string s1 = bs1.to_string(), s2 = bs2.to_string();
        // int res = 0;
        // for (int i=0; i<20; i++){
        //     if (s1[i] == '0' && s2[i] == '1'){
        //         return -1;
        //     }
        //     if (s1[i] == '1' && s2[i] == '0'){
        //         res++;
        //     }
        // }
        // return res;
    }
};

int main(){
    Solution s;
    int n = 14, k = 4;
    cout << s.minChanges(n, k) << endl;
}
