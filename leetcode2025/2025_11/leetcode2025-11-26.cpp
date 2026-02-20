#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int modNum, m, n, K;
    vector<vector<int>> dirs, GRID;
    unordered_map<long long, int> memo;
    int dfs(int x, int y, int tot){
        if (x==m-1 && y==n-1){
            return (tot==0);
        }
        long long key = (long long)x<<48 | (long long)y<<32 | tot;
        if (memo.count(key)){
            return memo[key];
        }
        int ans = 0;
        for (int i=0; i<2; i++){
            int dx=dirs[i][0], dy=dirs[i][1];
            int nx=x+dx, ny=y+dy;
            if (nx >= m || ny >= n){
                continue;
            }
            ans = (ans+dfs(nx, ny, (tot+GRID[nx][ny])%K))%modNum;
        }
        memo[key] = ans;
        return ans;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        modNum = 1e9+7;
        m = grid.size();
        n = grid[0].size();
        dirs = {{1,0},{0,1}};
        GRID = grid;
        K = k;
        return dfs(0, 0, grid[0][0]%k);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int k = 3;
    cout << s.numberOfPaths(grid, k) << endl;
}
