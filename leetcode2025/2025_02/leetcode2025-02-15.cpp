#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);
        for (int j=0; j<n; j++){
            int y = j;
            bool flag = true;
            for (int i=0; i<m; i++){
                if (grid[i][y]==1 && (y<n-1 && grid[i][y+1]==1)){
                    y++;
                }
                else if (grid[i][y]==-1 && (y>0 && grid[i][y-1]==-1)){
                    y--;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if (flag){
                res[j] = y;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    vector<int> res = s.findBall(grid);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
