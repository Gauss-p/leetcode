#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int m,n,tot;
    vector<vector<int>> dirs;
    vector<int> visited;
    vector<vector<char>> Grid;

    bool dfs(int indx, int pa){
        if (visited[indx] == 1){
            return true;
        }
        bool ans = false;
        visited[indx] = 1;
        int x = indx/n, y = indx%n;
        for (int i=0; i<4; i++){
            int dx = dirs[i][0], dy = dirs[i][1];
            int nx = x+dx, ny = y+dy;
            if (nx<0 || nx>=m || ny<0 || ny>=n){
                continue;
            }
            int nIndx = nx*n+ny;
            if (Grid[nx][ny] == Grid[x][y] && nIndx != pa){
                ans |= dfs(nIndx, indx);
            }
        }
        return ans;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        Grid = grid;
        m = grid.size();
        n = grid[0].size();
        tot = m*n;
        dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        visited.resize(tot, 0);

        for (int i=0; i<tot; i++){
            if (visited[i] == 0){
                bool res = dfs(i, -1);
                if (res){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    cout << s.containsCycle(grid) << endl;
}
