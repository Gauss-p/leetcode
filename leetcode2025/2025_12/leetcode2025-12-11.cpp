#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // 首先计算出每一行中第一个和最后一个建筑的位置，然后计算出每一列中第一个和最后一个建筑的位置，这样，再次循环所有建筑，如果其所在行位于其所在列对应的最小行和最大行之间，且其所在列位于其所在行对应的最小列和最大列之间，就说明该建筑被覆盖，答案加1
        vector<int> rowMin(n, INT_MAX), rowMax(n, INT_MIN), colMin(n, INT_MAX), colMax(n, INT_MIN);
        for (auto& b : buildings){
            int x=b[0]-1, y=b[1]-1;
            rowMin[x] = min(rowMin[x], y);
            rowMax[x] = max(rowMax[x], y);
            colMin[y] = min(colMin[y], x);
            colMax[y] = max(colMax[y], x);
        }
        int res = 0;
        for (auto& b : buildings){
            int x=b[0]-1, y=b[1]-1;
            if (y>rowMin[x] && y<rowMax[x] && x>colMin[y] && x<colMax[y]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> buildings = {{1,2},{2,2},{3,2},{2,1},{2,3}};
    cout << s.countCoveredBuildings(n, buildings) << endl;
}
