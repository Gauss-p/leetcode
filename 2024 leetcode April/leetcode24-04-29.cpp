class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i=0; i<m; i++){
            vector<int> tmp;
            for (int j=0; j<n; j++){
                if (i+j >= m) break;
                tmp.push_back(mat[j][i+j]);
            }
            sort(tmp.begin(), tmp.end());
            for (int j=0; j<n; j++){
                if (i+j >= m) break;
                mat[j][i+j] = tmp[j];
            }
        }
        for (int i=0; i<n; i++){
            vector<int> tmp;
            for (int j=0; j<m; j++){
                if (i+j >= n) break;
                tmp.push_back(mat[i+j][j]);
            }
            sort(tmp.begin(), tmp.end());
            for (int j=0; j<m; j++){
                if (i+j >= n) break;
                mat[i+j][j] = tmp[j];
            }
        }
        return mat;
    }
};
