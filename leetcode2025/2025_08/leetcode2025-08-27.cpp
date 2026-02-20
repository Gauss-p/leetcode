#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> dirs, Grid;
    unordered_map<long long, int> memo;

    int dfs(int x, int y, int curDir, bool is_turned, int target){
        int nx = x+dirs[curDir][0], ny = y+dirs[curDir][1];
        if (nx<0 || nx>=m || ny<0 || ny>=n || Grid[nx][ny] != target){
            return 0;
        }
        long long key = (long long)x<<32 | (long long)y<<16 | curDir<<3 | is_turned<<2 | target;
        if (memo.count(key)){
            return memo[key];
        }

        int ans = dfs(nx, ny, curDir, is_turned, 2-target);
        if (!is_turned){
            ans = max(ans, dfs(nx, ny, (curDir+1)%4, true, 2-target));
        }
        memo[key] = ans+1;
        return ans+1;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        Grid = grid;

        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    for (int d=0; d<4; d++){
                        res = max(res, dfs(i, j, d, false, 2)+1);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    cout << s.lenOfVDiagonal(grid) << endl;
}
