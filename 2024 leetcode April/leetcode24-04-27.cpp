class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<int> res(n, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                string tmp_string = to_string(grid[j][i]);
                int tmp = tmp_string.size();
                res[i] = max(res[i], tmp);
            }
        }
        return res;
    }
};
