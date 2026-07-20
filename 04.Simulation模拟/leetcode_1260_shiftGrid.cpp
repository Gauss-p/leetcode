#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int cur = i*n+j;
                int nxt = (cur+k)%(m*n);
                int x = nxt/n, y = nxt%n;
                res[x][y] = grid[i][j];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 1;
    vector<vector<int>> res = s.shiftGrid(grid, k);
    for (auto& r : res){
        for (int i : r){
            cout << i << " ";
        }
        cout << endl;
    }
}
