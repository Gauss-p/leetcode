#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                res += (grid[i][j] < 0);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{4,3,2,1},{3,2,-1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << s.countNegatives(grid) << endl;
}
