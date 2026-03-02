#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int calc(vector<int>& row){
        int cnt = 0;
        for (int i=row.size()-1; i>=0; i--){
            if (row[i] == 1){
                break;
            }
            cnt++;
        }
        return cnt;
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> newGrid;
        for (auto& row : grid){
            newGrid.push_back(calc(row));
        }

        int n = grid.size();
        int res = 0;
        for (int i=0; i<n; i++){
            if (newGrid[i] >= n-i-1){
                continue;
            }
            int indx = i+1;
            while (indx < n && newGrid[indx] < n-i-1){
                indx++;
            }
            if (indx == n){
                return -1;
            }
            int tmp = newGrid[indx];
            newGrid.erase(newGrid.begin()+indx);
            newGrid.insert(newGrid.begin()+i, tmp);
            res += indx-i;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};
    cout << s.minSwaps(grid) << endl;
}
