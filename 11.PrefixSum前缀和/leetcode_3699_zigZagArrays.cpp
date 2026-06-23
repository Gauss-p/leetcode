#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        r -= l;
        int modNum = 1e9+7;
        int m = r+1;

        vector<long long> dp0(m, 1);
        vector<long long> dp1(m, 1);
        for (int i=1; i<n; i++){
            vector<long long> ps0(m+1, 0), ps1(m+1, 0);
            for (int j=0; j<m; j++){
                ps0[j+1] = ps0[j]+dp0[j];
                ps1[j+1] = ps1[j]+dp1[j];
            }
            for (int j=0; j<=r; j++){
                dp0[j] = ps1[j]%modNum;
                dp1[j] = (ps0[m]-ps0[j+1])%modNum;
            }
        }
        long long res = 0;
        for (long long i : dp0){
            res = (res+i)%modNum;
        }
        for (long long i : dp1){
            res = (res+i)%modNum;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3, l = 4, r = 5;
    cout << s.zigZagArrays(n, l, r) << endl;
}
