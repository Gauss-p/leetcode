#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> leftOnes(m, vector<int>(n+1, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == '0'){
                    leftOnes[i][j+1] = 0;
                }
                else{
                    leftOnes[i][j+1] = leftOnes[i][j]+1;
                }
            }
        }
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int maxLength = INT_MAX;
                for (int k=i; k>=0; k--){
                    maxLength = min(maxLength, leftOnes[k][j+1]);
                    res = max(res, maxLength*(i-k+1));
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix = {{'1'}};
    cout << s.maximalRectangle(matrix) << endl;
}
