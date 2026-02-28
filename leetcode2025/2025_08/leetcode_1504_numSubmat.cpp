#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> leftOne(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            int cur = 0;
            for (int j=0; j<n; j++){
                if (mat[i][j] == 1){
                    cur++;
                }
                else{
                    cur = 0;
                }
                leftOne[i][j] = cur;
            }
        }

        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int minX = INT_MAX;
                for (int k=i; k>=0; k--){
                    if (minX == 0){
                        break;
                    }
                    minX = min(minX, leftOne[k][j]);
                    res += minX;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};
    cout << s.numSubmat(mat) << endl;
}
