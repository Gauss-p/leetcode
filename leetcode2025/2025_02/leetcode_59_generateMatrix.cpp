#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<vector<int>> dirs;
    int N;

    void dfs(int i, int x, int y, int lastDir){
        if (i == N*N+1){
            return;
        }
        res[x][y] = i;
        int nx = x+dirs[lastDir][0], ny = y+dirs[lastDir][1];
        if (nx>=0 && nx<N && ny>=0 && ny<N && res[nx][ny] == 0){
            dfs(i+1, nx, ny, lastDir);
        }
        else{
            int nDir = (lastDir+1)%4;
            int tmpx = x+dirs[nDir][0], tmpy = y+dirs[nDir][1];
            dfs(i+1, tmpx, tmpy, nDir);
        }
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        res.resize(n, vector<int>(n, 0));
        N = n;
        dfs(1, 0, 0, 0);
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> res = s.generateMatrix(n);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
