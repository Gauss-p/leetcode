#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;

class Solution {
private:
    int myBit_width(int a){
        int p = 0;
        while (a){
            a >>= 1;
            p++;
        }
        return p;
    }
    long long calc(int x){
        if (x == 0){
            return 0;
        }
        int m = myBit_width((uint32_t) x);
        long long ans = 0;
        for (int i=1; i<m; i++){
            ans += 1ll*((i+1)/2)*(1<<(i-1));
        }
        return ans+1ll*((m+1)/2)*(x-(1<<(m-1))+1);
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for (auto& q : queries){
            int l = q[0], r = q[1];
            res += (calc(r)-calc(l-1)+1)/2;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> queries = {{1,2},{2,4}};
    cout << s.minOperations(queries) << endl;
}
