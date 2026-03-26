#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    long long tot;
    vector<vector<int>> trans(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> newGrid(n, vector<int>(m, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                newGrid[j][i] = grid[i][j];
            }
        }
        return newGrid;
    }
    
    void upside_down(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m/2; i++){
            for (int j=0; j<n; j++){
                swap(grid[i][j], grid[m-1-i][j]);
            }
        }
    }

    bool calc(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        unordered_set<long long> cnt;
        cnt.insert(0);
        long long cur = 0;
        for (int i=0; i<m-1; i++){
            for (int j=0; j<n; j++){
                cur += grid[i][j];
                if (i > 0 || j == 0 || j == n-1){
                    cnt.insert(grid[i][j]);
                }
            }
            if (n == 1){
                if (cur == tot-cur || 2*cur-tot == grid[0][0] || 2*cur-tot == grid[i][0]){
                    return true;
                }
                continue;
            }
            if (cnt.count(2*cur-tot)){
                return true;
            }
            if (i == 0){
                for (int j=0; j<n; j++){
                    cnt.insert(grid[i][j]);
                }
            }
        }
        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        tot = 0;
        for (auto& r : grid){
            for (auto& x : r){
                tot += x;
            }
        }

        vector<vector<int>> transGrid = trans(grid);
        bool res1 = calc(grid);
        upside_down(grid);
        bool res2 = calc(grid);

        bool res3 = calc(transGrid);
        upside_down(transGrid);
        bool res4 = calc(transGrid);
        return res1|res2|res3|res4;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,4},{2,3}};
    cout << s.canPartitionGrid(grid) << endl;
}
