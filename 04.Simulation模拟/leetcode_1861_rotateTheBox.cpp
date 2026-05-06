#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        for (int i=0; i<m; i++){
            int cnt = 0;
            for (int j=0; j<n; j++){
                char cur = boxGrid[i][j];
                if (cur == '#'){
                    cnt++;
                    boxGrid[i][j] = '.';
                }
                if (cur == '*'){
                    for (int k=0; k<cnt; k++){
                        boxGrid[i][j-k-1] = '#';
                    }
                    cnt = 0;
                }
                if (j == n-1){
                    for (int k=0; k<cnt; k++){
                        boxGrid[i][j-k] = '#';
                    }
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                res[j][m-i-1] = boxGrid[i][j];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> boxGrid = {{'#', '.', '#'}};
    vector<vector<char>> res = s.rotateTheBox(boxGrid);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
