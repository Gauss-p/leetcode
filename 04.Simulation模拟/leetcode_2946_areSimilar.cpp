#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        for (auto& row : mat){
            for (int i=0; i<n; i++){
                if (row[i] != row[(i+k)%n]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 4;
    cout << s.areSimilar(mat, k) << endl;
}
