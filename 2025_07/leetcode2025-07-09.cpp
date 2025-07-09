#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<vector<int>> events = {{0,0}};
        for (int i=0; i<n; i++){
            events.push_back({startTime[i], endTime[i]});
        }
        events.push_back({eventTime, eventTime});
        int cur = 0;
        int res = 0;
        for (int i=1; i<=n; i++){
            cur += events[i][1]-events[i][0];
            if (i-1<k-1){
                continue;
            }
            res = max(res, events[i+1][0]-events[i-k][1]-cur);
            cur -= events[i-k+1][1]-events[i-k+1][0];
        }
        return res;
    }
};

int main(){
    Solution s;
    int eventTime = 5, k = 1;
    vector<int> startTime = {1,3}, endTime = {2,5};
    cout << s.maxFreeTime(eventTime, k, startTime, endTime) << endl;
}
