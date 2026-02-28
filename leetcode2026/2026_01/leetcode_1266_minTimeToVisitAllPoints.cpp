#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i=0; i<points.size()-1; i++){
            res += max(abs(points[i+1][0]-points[i][0]), abs(points[i+1][1]-points[i][1]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    cout << s.minTimeToVisitAllPoints(points) << endl;
}
