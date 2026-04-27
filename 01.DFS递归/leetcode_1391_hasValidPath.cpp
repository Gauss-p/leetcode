#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int m,n,tot;
    vector<vector<int>> Grid;
    vector<vector<vector<int>>> dirs;
    vector<int> visited;
    bool dfs(int indx){
        if (indx == tot-1){
            return true;
        }
        visited[indx] = 1;
        bool ans = false;
        int x = indx/n, y = indx%n;
        int cur = Grid[x][y];
        for (int d=0; d<2; d++){
            int dx = dirs[cur][d][0], dy = dirs[cur][d][1];
            int nx = x+dx, ny = y+dy;
            if (nx<0 || nx>=m || ny<0 || ny>=n || visited[nx*n+ny]==1){
                continue;
            }
            int nxt = Grid[nx][ny];
            if ((dirs[nxt][0][0]==-dx && dirs[nxt][0][1]==-dy) ||
                (dirs[nxt][1][0]==-dx && dirs[nxt][1][1]==-dy)){
                ans |= dfs(nx*n+ny);
            }
        }
        return ans;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        dirs = {{{}},
            {{0,1},{0,-1}},
            {{1,0},{-1,0}},
            {{0,-1},{1,0}},
            {{1,0},{0,1}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}};
        m = grid.size();
        n = grid[0].size();
        tot = m*n;
        visited.resize(tot, 0);
        Grid = grid;
        return dfs(0);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,4,3},{6,5,2}};
    cout << s.hasValidPath(grid) << endl;
}
