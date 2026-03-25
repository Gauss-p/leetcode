#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    long long tot;
    bool calc(vector<long long>& v){
        long long s = 0;
        for (int i : v){
            s += i;
            if (s*2 == tot){
                return true;
            }
        }
        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rows(m, 0), cols(n, 0);
        tot = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                tot += grid[i][j];
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        return calc(rows) | calc(cols);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,4},{2,3}};
    cout << s.canPartitionGrid(grid) << endl;
}
