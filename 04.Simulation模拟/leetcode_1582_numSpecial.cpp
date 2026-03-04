#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> colSum(n, 0), rowSum(m, 0);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                colSum[j] += mat[i][j];
                rowSum[i] += mat[i][j];
            }
        }
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    cout << s.numSpecial(mat) << endl;
}
