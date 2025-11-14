#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+2, vector<int>(n+2, 0));
        for (auto& q : queries){
            int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            diff[r1+1][c1+1] += 1;
            diff[r1+1][c2+2] -= 1;
            diff[r2+2][c1+1] -= 1;
            diff[r2+2][c2+2] += 1;
        }

        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                diff[i+1][j+1] = diff[i+1][j+1]+diff[i][j+1]+diff[i+1][j]-diff[i][j];
                res[i][j] = diff[i+1][j+1];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> queries = {{1,1,2,2},{0,0,1,1}};
    vector<vector<int>> res = s.rangeAddQueries(n, queries);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
