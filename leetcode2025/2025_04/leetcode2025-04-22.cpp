#include <iostream>
#include <vector>
using namespace std;

int ModNum = 1e9+7;
int MaxN = 1e4;
int MaxK = 13;
vector<vector<int>> Exp(MaxN+1);
vector<vector<int>> C(MaxN+MaxK, vector<int>(MaxK+1));

int init = [](){
    for (int x=0; x<=MaxN; x++){
        int tmp = x;
        int i = 2;
        while (i*i <= tmp){
            int cnt = 0;
            while (tmp%i == 0){
                cnt++;
                tmp /= i;
            }
            if (cnt>0){
                Exp[x].push_back(cnt);
            }
            i++;
        }
        if (tmp>1){
            Exp[x].push_back(1);
        }
    }

    for (int i=0; i<=MaxN+MaxK-1; i++){
        C[i][0] = 1;
        for (int j=1; j<=min(i, MaxK); j++){
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%ModNum;
        }
    }

    return 0;
}();

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        long long totRes = 0;
        for (int i=1; i<=maxValue; i++){
            long long res = 1;
            for (int k : Exp[i]){
                res = (res*1ll*C[n+k-1][k])%ModNum;
            }
            totRes = (totRes+res)%ModNum;
        }
        return totRes;
    }
};

int main(){
    Solution s;
    int n = 2, maxValue = 5;
    cout << s.idealArrays(n, maxValue) << endl;
}
