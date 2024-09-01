#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// 3276题解：https://leetcode.cn/problems/select-cells-in-grid-with-maximum-score/solutions/2900199/dpdong-tai-gui-hua-vs-dfsshen-du-you-xia-68rv
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int res = 0;
        for (int i=0; i<n; i++){
            if (startTime[i]<=queryTime && endTime[i]>=queryTime){
                res++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> startTime = {1,2,3}, endTime = {3,2,7};
    int queryTime = 4;
    Solution s;
    cout << s.busyStudent(startTime, endTime, queryTime) << endl;
}
