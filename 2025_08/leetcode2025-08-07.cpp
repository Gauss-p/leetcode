#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        f[0][n-1] = fruits[0][n-1];
        for (int i=1; i<n; i++){
            for (int j=i+1; j<n; j++){
                f[i][j] = max(f[i-1][j-1], f[i-1][j]);
                if (j+1 < n){
                    f[i][j] = max(f[i][j], f[i-1][j+1]);
                }
                f[i][j] += fruits[i][j];
            }
        }
        
        f[n-1][0] = fruits[n-1][0];
        for (int j=1; j<n; j++){
            for (int i=j+1; i<n; i++){
                f[i][j] = max(f[i-1][j-1], f[i][j-1]);
                if (i+1 < n){
                    f[i][j] = max(f[i][j], f[i+1][j-1]);
                }
                f[i][j] += fruits[i][j];
            }
        }
        
        int res = 0;
        for (int i=0; i<n; i++){
            res += fruits[i][i];
        }
        return res+f[n-1][n-2]+f[n-2][n-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> fruits = {{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
    cout << s.maxCollectedFruits(fruits) << endl;
}
