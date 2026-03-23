#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> Grid;
    int m, n;

    long long dfs(int i, int j, long long prod){
        if (i == m-1 && j == n-1){
            return prod<0 ? -1 : prod;
        }
        if (prod == 0){
            return 0;
        }
        long long res = -1;
        if (i+1 < m){
            res = max(res, dfs(i+1, j, prod*Grid[i+1][j]));
        }
        if (j+1 < n){
            res = max(res, dfs(i, j+1, prod*Grid[i][j+1]));
        }
        return res;
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        Grid = grid;
        m = grid.size();
        n = grid[0].size();
        int modNum = 1e9+7;
        long long res = dfs(0, 0, grid[0][0]);
        return res==-1 ? -1 : res%modNum;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,-2,1},{1,-2,1},{3,-4,1}};
    cout << s.maxProductPath(grid) << endl;
}
