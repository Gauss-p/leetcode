#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> Grid;
    bool dfs(int x, int y){
        if (x<0 || x>=m || y<0 || y>=n){
            return false;
        }
        if (Grid[x][y] != 0){
            return true;
        }
        Grid[x][y] = -1;
        bool res1 = dfs(x-1, y);
        bool res2 = dfs(x, y-1);
        bool res3 = dfs(x+1, y);
        bool res4 = dfs(x, y+1);
        return res1&&res2&&res3&&res4;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        Grid = grid;
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (Grid[i][j] == 0){
                    res += dfs(i, j);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};
    cout << s.closedIsland(grid) << endl;
}
