#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int mx = 0;
        for (auto& row : grid){
            for (auto& x : row){
                mx = max(x, mx);
            }
        }

        int res = 0;
        vector<int> sufMin(mx+2, INT_MAX);
        for (int cnt=0; cnt<=k; cnt++){
            vector<int> minF(mx+1, INT_MAX);
            vector<int> f(n+1, INT_MAX);
            f[1] = -grid[0][0];
            for (auto& row : grid){
                
                for (int j=0; j<n; j++){
                    int x = row[j];
                    f[j+1] = min(min(f[j], f[j+1])+x, sufMin[x]);
                    minF[x] = min(minF[x], f[j+1]);
                }
            }
            for (int i=mx; i>=0; i--){
                sufMin[i] = min(sufMin[i+1], minF[i]);
            }
            res = f[n];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,3,3},{2,5,4},{4,3,5}};
    int k = 2;
    cout << s.minCost(grid, k) << endl;
}
