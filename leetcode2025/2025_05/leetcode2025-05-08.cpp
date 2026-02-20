#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mT) {
        int m = mT.size(), n = mT[0].size();
        // for (int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
                
        //     }
        // }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0,0,0,0});
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> orient = {{0,1},{1,0},{0,-1},{-1,0}};// 右下左上
        while (!q.empty()){
            auto& tmp = q.top();
            int x = tmp[1], y = tmp[2], lastTimes = tmp[3];
            q.pop();
            if (vis[x][y]){
                continue;
            }
            vis[x][y] = 1;
            for (int i=0; i<4; i++){
                int nx = x+orient[i][0], ny = y+orient[i][1];
                if (nx>=0 && nx<m && ny>=0 && ny<n){
                    if (vis[nx][ny]) continue;
                    int tmpTime = minTime[x][y];
                    if (tmpTime < mT[nx][ny]){
                        tmpTime = mT[nx][ny];
                    }
                    tmpTime++;
                    tmpTime += (lastTimes%2);
                    if (tmpTime < minTime[nx][ny]){
                        minTime[nx][ny] = tmpTime;
                        // cout << nx << " " << ny << " " << tmpTime << endl;
                        q.push({tmpTime, nx, ny, lastTimes+1});
                    }
                }
            }
        }
        return minTime[m-1][n-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> mT = {{0,4},{4,4}};
    cout << s.minTimeToReach(mT) << endl;
}
