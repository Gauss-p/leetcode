#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> rotate(vector<vector<int>>& mat){
        vector<vector<int>> newMat(n, vector<int>(n, 0));
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                newMat[i][j] = mat[n-j-1][i];
            }
        }
        return newMat;
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        for (int i=0; i<4; i++){
            if (mat == target){
                return true;
            }
            mat = rotate(mat);
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{0,1},{1,0}};
    vector<vector<int>> target = {{1,0},{0,1}};
    cout << s.findRotation(mat, target) << endl;
}
