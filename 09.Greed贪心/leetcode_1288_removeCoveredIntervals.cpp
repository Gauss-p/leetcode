#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        int res = intervals.size();
        int maxRight = 0;
        for (int i=0; i<intervals.size(); i++){
            int l = intervals[i][0], r = intervals[i][1];
            if (r <= maxRight){
                res--;
            }
            else{
                maxRight = r;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};
    cout << s.removeCoveredIntervals(intervals) << endl;
}
