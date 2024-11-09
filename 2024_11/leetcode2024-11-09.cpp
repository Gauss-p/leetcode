#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class NeighborSum {
private:
    int n;
    vector<vector<int>> mat;
    unordered_map<int, pair<int, int>> pos;
public:
    NeighborSum(vector<vector<int>>& grid) {
        mat = grid;
        n = mat.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                pos[mat[i][j]] = make_pair(i, j);
            }
        }
    }

    int mySum(vector<vector<int>> &dir, int x, int y){
        int res = 0;
        for (int i=0; i<4; i++){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if (nx>=0 && nx<n && ny>=0 && ny<n){
                res += mat[nx][ny];
            }
        }
        return res;
    }
    
    int adjacentSum(int value) {
        int x = pos[value].first, y = pos[value].second;
        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        return mySum(dir, x, y);
    }
    
    int diagonalSum(int value) {
        int x = pos[value].first, y = pos[value].second;
        vector<vector<int>> dir = {{-1,-1},{1,-1},{-1,1},{1,1}};
        return mySum(dir, x, y);
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main(){
    vector<vector<int>> grid = {{0,1,2},{3,4,5},{6,7,8}};
    NeighborSum ns = NeighborSum(grid);
    cout << ns.adjacentSum(1) << " ";
    cout << ns.adjacentSum(4) << " ";
    cout << ns.diagonalSum(4) << " ";
    cout << ns.diagonalSum(8) << endl;
}
