#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> mat(m+1, vector<pair<int, int>>(n+1, make_pair(0, 0)));
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                mat[i+1][j+1].first = mat[i+1][j].first+mat[i][j+1].first-mat[i][j].first+(grid[i][j]=='X');
                mat[i+1][j+1].second = mat[i+1][j].second+mat[i][j+1].second-mat[i][j].second+(grid[i][j]=='Y');
                if (mat[i+1][j+1].first==mat[i+1][j+1].second && mat[i+1][j+1].first){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid = {{'X','Y','.'},{'Y','.','.'}};
    cout << s.numberOfSubmatrices(grid) << endl;
}
