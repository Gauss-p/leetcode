#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int m,n;
    unordered_map<char, int> val;
    unordered_map<long long, int> memo;
    vector<vector<char>> Grid;
    bool dfs(int i, int j, int cnt){
        if (i==m-1 && j==n-1){
            return (cnt==0);
        }
        if (cnt >= (m+n+1)/2){
            return false;
        }
        long long key = (long long)i<<30 | (long long)j<<20 | cnt;
        if (memo.count(key)){
            return memo[key];
        }
        bool ans = false;
        if (i<m-1 && cnt+val[Grid[i+1][j]] >= 0){
            ans |= dfs(i+1, j, cnt+val[Grid[i+1][j]]);
        }
        if (j<n-1 && cnt+val[Grid[i][j+1]] >= 0){
            ans |= dfs(i, j+1, cnt+val[Grid[i][j+1]]);
        }
        memo[key] = ans;
        return ans;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        Grid = grid;
        m = grid.size();
        n = grid[0].size();
        if ((m+n-1)&1){
            return false;
        }
        val['('] = 1;
        val[')'] = -1;
        return (grid[0][0]=='(' && grid[m-1][n-1]==')') ? dfs(0, 0, 1) : false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid = {{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};
    cout << s.hasValidPath(grid) << endl;
}
