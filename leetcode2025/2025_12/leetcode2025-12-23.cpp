#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return (a[1] < b[1]);
        });
        int n = events.size();
        vector<int> endTime(n);
        vector<int> preMax(n+1, 0);
        for (int i=0; i<n; i++){
            endTime[i] = events[i][1];
            preMax[i+1] = max(preMax[i], events[i][2]);
        }
        
        int res = preMax[n-1];
        for (int i=0; i<n; i++){
            int end = events[i][0]-1;
            int indx = lower_bound(endTime.begin(), endTime.end(), end+1)-endTime.begin()-1;
            res = max(res, events[i][2]+preMax[indx+1]);
        }
        return res;
    }
};
// 这是协同测试的小例子
// This is an example of cooperate test.
// hahah!
// 你要干嘛
// 我只是觉得好玩而已
// 哦
// 你赶快写完吧
// 现在就好了哦
// 呵呵

int main(){
    Solution s;
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    cout << s.maxTwoEvents(events) << endl;
}
