#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<vector<int>> G;
    bool isMagicSquare(int i, int j){
        unordered_map<int, int> tot;
        vector<int> row(3, 0), col(3, 0), dia(2, 0);
        for (int x=0; x<3; x++){
            for (int y=0; y<3; y++){
                int cur = G[i+x][j+y];
                tot[cur]++;
                if (cur==0 || cur>=10 || tot[cur]==2){
                    return false;
                }
                row[x] += cur;
                col[y] += cur;
                if (x==y) dia[0] += cur;
                if (x+y==2) dia[1] += cur;
            }
        }
        return (row[0]==row[1] && row[1]==row[2] && col[0]==col[1] && col[1]==col[2] && dia[0]==dia[1]);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        G = grid;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i=0; i<m-2; i++){
            for (int j=0; j<n-2; j++){
                if (isMagicSquare(i, j)){
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    cout << s.numMagicSquaresInside(grid) << endl;
}
