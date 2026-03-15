#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> workTime;
        for (int x : workerTimes){
            workTime.push({x, x, 1});
        }

        long long res = 0;
        for (int i=0; i<mountainHeight; i++){
            vector<long long> cur = workTime.top();
            workTime.pop();
            long long t = cur[0], base = cur[1], n = cur[2];
            res = max(res, t);
            workTime.push({t+base*(n+1), base, n+1});
        }
        return res;
    }
};

int main(){
    Solution s;
    int mountainHeight = 4;
    vector<int> workerTimes = {2,1,1};
    cout << s.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
}
