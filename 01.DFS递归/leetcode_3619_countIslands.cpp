#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n, kk;
    vector<vector<int>> Grid;
    int dfs(int x, int y){
        if (x<0 || x>=m || y<0 || y>=n || Grid[x][y]==0){
            return 0;
        }
        int res = Grid[x][y]%kk;
        Grid[x][y] = 0;
        res = (res+(dfs(x+1, y)+dfs(x, y+1)+dfs(x-1, y)+dfs(x, y-1))%kk)%kk;
        return res;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        Grid = grid;
        m = grid.size();
        n = grid[0].size();
        kk = k;
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (Grid[i][j] > 0){
                    res += (dfs(i, j)%k == 0);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
    int k = 5;
    cout << s.countIslands(grid, k) << endl;
}
