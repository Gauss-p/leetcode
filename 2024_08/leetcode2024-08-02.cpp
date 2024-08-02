#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> col(m, 0), row(n, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                col[j] += grid[i][j];
                row[i] += grid[i][j];
            }
        }
        long long res = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    res += 1ll*(col[j]-1)*(row[i]-1);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,0},{0,1,1},{0,1,0}};
    cout << s.numberOfRightTriangles(grid) << endl;
}
