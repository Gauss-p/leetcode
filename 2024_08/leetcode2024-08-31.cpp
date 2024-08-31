#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dir = {{0,0},{0,1},{1,0},{1,1}};
        for (int i=0; i<m-1; i++){
            for (int j=0; j<n-1; j++){
                int b=0, w=0;
                for (auto k : dir){
                    if (grid[i+k[0]][j+k[1]] == 'B'){
                        b++;
                    }
                    else{
                        w++;
                    }
                }
                if (min(b, w) <= 1){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> grid = {{'B','W','B'},{'B','W','W'},{'B','W','B'}};
    cout << s.canMakeSquare(grid) << endl;
}
