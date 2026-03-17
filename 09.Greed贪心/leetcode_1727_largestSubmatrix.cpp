#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rod(n, 0);
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                rod[j] = matrix[i][j]==0 ? 0 : rod[j]+1;
            }

            vector<int> sortedRod = rod;
            sort(sortedRod.begin(), sortedRod.end());
            for (int k=0; k<n; k++){
                res = max(res, (n-k)*sortedRod[k]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    cout << s.largestSubmatrix(matrix) << endl;
}
