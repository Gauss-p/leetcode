#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rowPreSum(m, vector<int>(n+1, 0));
        vector<vector<int>> colPreSum(m+1, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int x = grid[i][j];
                rowPreSum[i][j+1] = rowPreSum[i][j]+x;
                colPreSum[i+1][j] = colPreSum[i][j]+x;
            }
        }

        for (int k=min(m, n); k>=1; k--){
            for (int i=0; i<=m-k; i++){
                for (int j=0; j<=n-k; j++){
                    unordered_set<int> totSt;
                    int dia1 = 0, dia2 = 0;
                    for (int x=0; x<k; x++){
                        totSt.insert(rowPreSum[i+x][j+k]-rowPreSum[i+x][j]);
                        totSt.insert(colPreSum[i+k][j+x]-colPreSum[i][j+x]);
                        dia1 += grid[i+x][j+x];
                        dia2 += grid[i+x][j+k-1-x];
                    }
                    totSt.insert(dia1);
                    totSt.insert(dia2);
                    if (totSt.size() == 1){
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
    vector<vector<int>> grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    cout << s.largestMagicSquare(grid) << endl;
}
