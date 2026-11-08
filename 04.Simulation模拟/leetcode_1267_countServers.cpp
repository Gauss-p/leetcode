#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> s1(m, 0), s2(n, 0);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                s1[i] += grid[i][j];
                s2[j] += grid[i][j];
            }
        }
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] && (s1[i]>1 || s2[j]>1)){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,0},{0,1}};
    cout << s.countServers(grid) << endl;
}
