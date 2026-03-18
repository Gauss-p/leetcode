#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                preSum[i+1][j+1] = preSum[i+1][j]+preSum[i][j+1]+grid[i][j]-preSum[i][j];
            }
        }

        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (preSum[i+1][j+1] > k){
                    break;
                }
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{7,6,3},{6,6,1}};
    int k = 18;
    cout << s.countSubmatrices(grid, k) << endl;
}
