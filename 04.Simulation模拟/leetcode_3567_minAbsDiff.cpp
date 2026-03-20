#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m-k+1, vector<int>(n-k+1, INT_MAX));
        for (int i=0; i<m-k+1; i++){
            for (int j=0; j<n-k+1; j++){
                vector<int> tot;
                for (int x=i; x<i+k; x++){
                    for (int y=j; y<j+k; y++){
                        tot.push_back(grid[x][y]);
                    }
                }
                sort(tot.begin(), tot.end());
                for (int indx=0; indx<tot.size()-1; indx++){
                    if (tot[indx+1] != tot[indx]){
                        res[i][j] = min(res[i][j], tot[indx+1]-tot[indx]);
                    }
                }
                res[i][j] = (res[i][j]==INT_MAX ? 0 : res[i][j]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,8},{3,-2}};
    int k = 2;
    vector<vector<int>> res = s.minAbsDiff(grid, k);
    for (auto i : res){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
