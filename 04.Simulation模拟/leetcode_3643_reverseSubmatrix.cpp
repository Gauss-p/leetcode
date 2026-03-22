#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i=0; i<k/2; i++){
            int row1 = x+i, row2 = x+k-i-1;
            for (int j=0; j<k; j++){
                swap(grid[row1][y+j], grid[row2][y+j]);
            }
        }
        return grid;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int x = 1, y = 0, k = 3;
    vector<vector<int>> res = s.reverseSubmatrix(grid, x, y, k);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
