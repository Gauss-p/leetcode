#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <bit>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1){
            return 'a';
        }
        k -= 1;
        int res = 0;
        int m = 64-__builtin_clzll(k*1ll); // __builtin_clz函数无法传入0
        // int m = bit_width((uint64_t) k);
        for (int i=m-1; i>=0; i--){
            if (k>>i & 1){
                res += operations[i];
            }
        }
        return 'a'+res%26;
    }
};

int main(){
    Solution s;
    int k = 1;
    vector<int> operations = {0,0,0};
    cout << s.kthCharacter(k, operations) << endl;
}
