#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    vector<int> fill;
    vector<int> getCircle(int x, int y, vector<int>& filling, vector<vector<int>>& grid){
        vector<int> circle;
        int indx = 0;
        for (int c=y; c<n-y-1; c++){
            circle.push_back(grid[x][c]);
            grid[x][c] = filling[indx];
            indx++;
        }
        for (int r=x; r<m-x-1; r++){
            circle.push_back(grid[r][n-y-1]);
            grid[r][n-y-1] = filling[indx];
            indx++;
        }
        for (int c=n-y-1; c>y; c--){
            circle.push_back(grid[m-x-1][c]);
            grid[m-x-1][c] = filling[indx];
            indx++;
        }
        for (int r=m-x-1; r>x; r--){
            circle.push_back(grid[r][y]);
            grid[r][y] = filling[indx];
            indx++;
        }
        return circle;
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        fill.resize(2*m+2*n, -1);

        vector<vector<int>> circles;
        for (int i=0; i<min(m/2, n/2); i++){
            circles.push_back(getCircle(i, i, fill, grid));
        }

        for (int i=0; i<min(m/2, n/2); i++){
            vector<int> cur = circles[i];
            int indx = k%cur.size();
            vector<int> newFill;
            for (int j=indx; j<indx+cur.size(); j++){
                newFill.push_back(cur[j%cur.size()]);
            }
            getCircle(i, i, newFill, grid);
        }
        return grid;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{40,10},{30,20}};
    int k = 1;
    vector<vector<int>> res = s.rotateGrid(grid, k);
    for (auto i : res){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
