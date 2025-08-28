#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> lst(n*2-1);
        for (int curDiff=-n+1; curDiff<n; curDiff++){
            for (int x=0; x<n; x++){
                int curY = x-curDiff;
                if (curY>=0 && curY<n){
                    lst[curDiff+n-1].push_back(grid[x][curY]);
                }
            }
            if (curDiff<0){
                sort(lst[curDiff+n-1].begin(), lst[curDiff+n-1].end());
            }
            else{
                sort(lst[curDiff+n-1].begin(), lst[curDiff+n-1].end(), greater<int>());
            }
        }

        for (int curDiff=-n+1; curDiff<n; curDiff++){
            for (int x=n-1; x>=0; x--){
                int curY = x-curDiff;
                if (curY>=0 && curY<n){
                    grid[x][curY] = lst[curDiff+n-1].back();
                    lst[curDiff+n-1].pop_back();
                }
            }
        }
        return grid;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};
    vector<vector<int>> res = s.sortMatrix(grid);
    for (auto i : res){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
