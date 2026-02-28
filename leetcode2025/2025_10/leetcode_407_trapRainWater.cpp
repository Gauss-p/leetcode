#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (i==0 || i==m-1 || j==0 || j==n-1){
                    pq.emplace(heightMap[i][j], i, j);
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        while (!pq.empty()){
            auto [curH, x, y] = pq.top();
            pq.pop();
            for (int d=0; d<4; d++){
                int nx=x+dirs[d][0], ny=y+dirs[d][1];
                if (nx<0 || nx>=m || ny<0 || ny>=n || visited[nx][ny]==1){
                    continue;
                }
                if (curH > heightMap[nx][ny]){
                    res += (curH-heightMap[nx][ny]);
                }
                pq.emplace(max(curH, heightMap[nx][ny]), nx, ny);
                visited[nx][ny] = 1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << s.trapRainWater(heightMap) << endl;
}
