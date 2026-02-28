#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l=INT_MAX, u=INT_MAX, d=0, r=0;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    l = min(l, j);
                    u = min(u, i);
                    d = max(d, i);
                    r = max(r, j);
                }
            }
        }
        return (r-l+1)*(d-u+1);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,0},{1,0,1}};
    cout << s.minimumArea(grid) << endl;
}
