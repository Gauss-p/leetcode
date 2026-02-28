#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<vector<int>> events = {{0,0}};
        for (int i=0; i<n; i++){
            events.push_back({startTime[i], endTime[i]});
        }
        events.push_back({eventTime, eventTime});

        vector<int> preMaxSpace(n+2, 0);
        for (int i=0; i<=n; i++){
            preMaxSpace[i+1] = max(preMaxSpace[i], events[i+1][0]-events[i][1]);
        }
        vector<int> afterMaxSpace(n+2, 0);
        for (int i=n; i>=0; i--){
            afterMaxSpace[i] = max(afterMaxSpace[i+1], events[i+1][0]-events[i][1]);
        }

        int res = 0;
        for (int i=1; i<=n; i++){
            int curLength = events[i][1]-events[i][0];
            int cur = events[i+1][0]-events[i-1][1]-curLength;
            if (preMaxSpace[i-1] >= curLength || afterMaxSpace[i+1] >= curLength){
                cur += curLength;
            }
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    int eventTime = 10;
    vector<int> startTime = {0,7,9}, endTime = {1,8,10};
    cout << s.maxFreeTime(eventTime, startTime, endTime) << endl;
}
