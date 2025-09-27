#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n = p.size();
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                for (int k=j+1; k<n; k++){
                    int cur = abs((p[j][0]-p[i][0])*(p[k][1]-p[i][1]) - (p[j][1]-p[i][1])*(p[k][0]-p[i][0]));
                    res = max(res, cur);
                }
            }
        }
        return 1.0*res/2;
    }
};

int main(){
    Solution s;
    vector<vector<int>> p = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << s.largestTriangleArea(p) << endl;
}
