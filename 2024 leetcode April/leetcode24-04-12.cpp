#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for (int i=0; i<n; i++){
            int cnt = 0;
            for (int j=0; j<n; j++){
                if (grid[j][i] == 0){
                    cnt++;
                }
            }
            if (cnt == n){
                res = i;
                break;
            }
        }
        return res;
        // int n = grid.size();
        // vector<vector<int>> v(n);
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<n; j++){
        //         if (grid[i][j] == 1){
        //             v[j].push_back(i);
        //         }
        //     }
        // }
        // int res = 0;
        // for (int i=0; i<n; i++){
        //     if (v[i].size() == 0){
        //         res = i;
        //         break;
        //     }
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1},{0,0}};
    cout << s.findChampion(grid) << endl;
    return 0;
}
