#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        set<pair<int, int>> setGuard;
        for (auto& g : guards){
            setGuard.emplace(g[0], g[1]);
        }
        set<pair<int, int>> setWall;
        for (auto& w : walls){
            setWall.emplace(w[0], w[1]);
        }
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> pos(m, vector<int>(n, 0));
        for (auto& g : guards){
            int x = g[0], y = g[1];
            for (auto& d : dirs){
                int dx = d[0], dy = d[1];
                int nx = x+dx, ny = y+dy;
                while (nx>=0 && nx<m && ny>=0 && ny<n && setGuard.count(make_pair(nx, ny))==0 && setWall.count(make_pair(nx, ny))==0){
                    pos[nx][ny] = 1;
                    nx += dx;
                    ny += dy;
                }
            }
        }
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                res += pos[i][j];
            }
        }
        return m*n-res-guards.size()-walls.size();
    }
};

int main(){
    Solution s;
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    cout << s.countUnguarded(m, n, guards, walls) << endl;
}
