#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        int res = 0;
        int n = points.size();
        for (int i=0; i<n; i++){
            int x1=points[i][0], y1=points[i][1];
            int maxY = INT_MIN;
            for (int j=i+1; j<n; j++){
                if (maxY >= y1){
                    break;
                }
                int x2=points[j][0], y2=points[j][1];
                if (y2<=y1 && y2>maxY){
                    maxY = y2;
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout << s.numberOfPairs(points) << endl;
}
