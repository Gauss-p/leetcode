#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long res = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int x2 = min(topRight[i][0], topRight[j][0]);
                int y2 = min(topRight[i][1], topRight[j][1]);
                int x_length = max(x2-x1, 0), y_length = max(y2-y1, 0);
                int edge = min(x_length, y_length);
                res = max(res, 1ll*edge*edge);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> bottomLeft = {{1,1},{2,2},{3,1}};
    vector<vector<int>> topRight = {{3,3},{4,4},{6,6}};
    cout << s.largestSquareArea(bottomLeft, topRight) << endl;
}
