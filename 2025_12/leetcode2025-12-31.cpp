#include <iostream>
#include <vector>
using namespace std;

class UFS{
private:
    vector<int> pa;
public:
    UFS(int n){
        pa.resize(n);
        for (int i=0; i<n; i++){
            pa[i] = i;
        }
    }

    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        pa[px] = py;
    }

    bool isSame(int x, int y){
        return find(x)==find(y);
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> land(row, vector<bool>(col, false));
        int top = row*col, bottom = row*col+1;
        UFS ufs(row*col+2);

        for (int i=cells.size()-1; i>=0; i--){
            int x = cells[i][0]-1, y = cells[i][1]-1;
            land[x][y] = true;
            int cur = x*col+y;
            if (x == 0){
                ufs.merge(cur, top);
            }
            if (x == row-1){
                ufs.merge(cur, bottom);
            }
            for (int d=0; d<4; d++){
                int nx = x+dirs[d][0], ny = y+dirs[d][1];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || !land[nx][ny]){
                    continue;
                }
                int nxt = nx*col+ny;
                ufs.merge(cur, nxt);
            }

            if (ufs.isSame(top, bottom)){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    int row = 2, col = 2;
    vector<vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};
    cout << s.latestDayToCross(row, col, cells) << endl;
}
