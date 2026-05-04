#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n-i; j++){
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
        for (int i=0; i<n/2; i++){
            swap(matrix[i], matrix[n-i-1]);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for (auto& i : matrix){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
