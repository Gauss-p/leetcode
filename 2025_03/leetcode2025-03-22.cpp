#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> res = {0,0};
        for (int i=0; i<n; i++){
            int cnt = 0;
            for (int j : mat[i]){
                cnt += j;
            }
            if (cnt > res[1]){
                res[0] = i;
                res[1] = cnt;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{0,1},{1,0}};
    vector<int> res = s.rowAndMaximumOnes(mat);
    cout << res[0] << " " << res[1] << endl;
}
