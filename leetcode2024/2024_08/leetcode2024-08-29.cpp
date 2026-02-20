#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<int>> st(grid.begin(), grid.end());
        vector<vector<int>> vvi(st.begin(), st.end());
        if (vvi.size() == 1){
            for (int j=0; j<n-1; j++){
                if (vvi[0][j] == vvi[0][j+1]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1},{2},{3}};
    cout << s.satisfiesConditions(grid) << endl;
}
