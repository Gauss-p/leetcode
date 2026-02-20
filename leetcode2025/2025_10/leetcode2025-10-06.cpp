#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, 0, 0);
        while (!pq.empty()){
            auto [t, x, y] = pq.top();
            pq.pop();
            if (visited[x][y]){
                continue;
            }
            visited[x][y] = 1;
            for (int i=0; i<4; i++){
                int dx=dirs[i][0], dy=dirs[i][1];
                int nx=x+dx, ny=y+dy;
                if (nx<0 || nx>=n || ny<0 || ny>=n){
                    continue;
                }
                int cur = max(t, max(grid[x][y], grid[nx][ny]));
                if (cur < dis[nx][ny]){
                    dis[nx][ny] = cur;
                    pq.emplace(cur, nx, ny);
                }
            }
        }
        return dis[n-1][n-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,2},{1,3}};
    cout << s.swimInWater(grid) << endl;
}
