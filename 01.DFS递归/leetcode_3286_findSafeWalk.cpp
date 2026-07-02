#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        unordered_map<long long, bool> mp;
        auto dfs = [&](auto&& dfs, int i, int j){
            health -= grid[i][j];
            if (health <= 0){
                health += grid[i][j];
                return false;
            }
            long long key = (long long)i<<32 | (long long)j<<16 | health;
            if (mp.count(key)){
                health += grid[i][j];
                return mp[key];
            }
            visited[i][j] = 1;
            if (i == m-1 && j == n-1){
                return true;
            }
            bool res = false;
            if (i > 0 && visited[i-1][j] == 0){
                res |= dfs(dfs, i-1, j);
            }
            if (i < m-1 && visited[i+1][j] == 0){
                res |= dfs(dfs, i+1, j);
            }
            if (j > 0 && visited[i][j-1] == 0){
                res |= dfs(dfs, i, j-1);
            }
            if (j < n-1 && visited[i][j+1] == 0){
                res |= dfs(dfs, i, j+1);
            }
            visited[i][j] = 0;
            health += grid[i][j];
            mp[key] = res;
            return res;
        };
        return dfs(dfs, 0, 0);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    int health = 1;
    cout << s.findSafeWalk(grid, health) << endl;
}
