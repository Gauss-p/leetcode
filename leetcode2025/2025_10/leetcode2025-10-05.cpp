#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> H, dirs;
    set<vector<int>> pacific, atlantic;
    void dfs(int i, int j, int last, set<vector<int>>& visited){
        if (i<0 || i>=m || j<0 || j>=n || H[i][j]<last || visited.count({i, j})){
            return;
        }
        visited.insert({i, j});
        for (int indx=0; indx<4; indx++){
            int dx=dirs[indx][0], dy=dirs[indx][1];
            int nx=i+dx, ny=j+dy;
            dfs(nx, ny, H[i][j], visited);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        H = heights;
        m = heights.size();
        n = heights[0].size();
        dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int j=0; j<n; j++){
            dfs(0, j, INT_MIN, pacific);
            dfs(m-1, j, INT_MIN, atlantic);
        }
        for (int i=0; i<m; i++){
            dfs(i, 0, INT_MIN, pacific);
            dfs(i, n-1, INT_MIN, atlantic);
        }
        set<vector<int>> res;
        set_intersection(pacific.begin(), pacific.end(), atlantic.begin(), atlantic.end(), inserter(res, res.begin()));
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = s.pacificAtlantic(heights);
    for (auto& i : res){
        cout << i[0] << " " << i[1] << endl;
    }
}
