#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                preSum[i+1][j+1] = preSum[i][j+1]+preSum[i+1][j]-preSum[i][j]+mat[i][j];
            }
        }

        for (int k=min(m, n); k>=1; k--){
            for (int i=0; i<=m-k; i++){
                for (int j=0; j<=n-k; j++){
                    int cur = preSum[i+k][j+k]-preSum[i][j+k]-preSum[i+k][j]+preSum[i][j];
                    if (cur <= threshold){
                        return k;
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    int threshold = 4;
    cout << s.maxSideLength(mat, threshold) << endl;
}
