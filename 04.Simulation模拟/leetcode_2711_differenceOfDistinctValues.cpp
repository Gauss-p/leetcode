#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int m,n;
    vector<vector<int>> res;
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        res.resize(m, vector<int>(n, 0));
        for (int i=0; i<n; i++){
            unordered_map<int, int> cnt;
            int x = 0, y = i;
            cnt[grid[x][y]]++;
            while (x+1<m && y+1<n){
                x++;
                y++;
                res[x][y] = cnt.size();
                cnt[grid[x][y]]++;
            }
            x = 0;
            y = i;
            while (x<m && y<n){
                cnt[grid[x][y]]--;
                if (cnt[grid[x][y]] == 0){
                    cnt.erase(grid[x][y]);
                }
                res[x][y] = abs(res[x][y]-(int)cnt.size());
                x++;
                y++;
            }
        }

        for (int i=1; i<m; i++){
            unordered_map<int, int> cnt;
            int x = i, y = 0;
            cnt[grid[x][y]]++;
            while (x+1<m && y+1<n){
                x++;
                y++;
                res[x][y] = cnt.size();
                cnt[grid[x][y]]++;
            }
            
            x = i;
            y = 0;
            while (x<m && y<n){
                cnt[grid[x][y]]--;
                if (cnt[grid[x][y]] == 0){
                    cnt.erase(grid[x][y]);
                }
                res[x][y] = abs(res[x][y]-(int)cnt.size());
                x++;
                y++;
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{3,1,5},{3,2,1}};
    vector<vector<int>> res = s.differenceOfDistinctValues(grid);
    for (auto&i : res){
        for (auto&j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
