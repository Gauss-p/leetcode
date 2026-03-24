#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int modNum = 12345;
        vector<vector<int>> res(m, vector<int>(n, 1));
        int prod = 1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                res[i][j] = (res[i][j]*prod)%modNum;
                prod = (1ll*grid[i][j]*prod)%modNum;
            }
        }

        prod = 1;
        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                res[i][j] = (res[i][j]*prod)%modNum;
                prod = (1ll*prod*grid[i][j])%modNum;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2},{3,4}};
    vector<vector<int>> res = s.constructProductMatrix(grid);
    for (auto& row : res){
        for (auto& i : row){
            cout << i << " ";
        }
        cout << endl;
    }
}
