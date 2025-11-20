#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto& a, auto& b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        int n = intervals.size();
        int res = 2;
        int cur = intervals.back()[0], nxt = cur+1;
        for (int i=n-2; i>=0; i--){
            int l = intervals[i][0], r = intervals[i][1];
            if (r >= nxt){
                continue;
            }
            if (r < cur){
                cur = l;
                nxt = l+1;
                res += 2;
            }
            else{
                nxt = cur;
                cur = l;
                res += 1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{3,7},{8,9}};
    cout << s.intersectionSizeTwo(intervals) << endl;
}
