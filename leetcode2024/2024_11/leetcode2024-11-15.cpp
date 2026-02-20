#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int HW(vector<vector<int>>& grid, int op){
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<(op==1 ? m : n); i++){
            int tmp = 0;
            for (int j=0; j<(op==1 ? n/2 : m/2); j++){
                if (op){
                    tmp += (grid[i][j]^grid[i][n-j-1]);
                }
                else{
                    tmp += (grid[j][i]^grid[m-j-1][i]);
                }
            }
            res += tmp;
        }
        return res;
    }

    int minFlips(vector<vector<int>>& grid) {
        return min(HW(grid, 0), HW(grid, 1));
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};
    cout << s.minFlips(grid) << endl;
}
