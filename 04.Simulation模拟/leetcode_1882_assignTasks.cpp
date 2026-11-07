#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; i++){
            pq.emplace(servers[i], i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> nonAvail;
        vector<int> res;
        long long t = 0;
        for (int i=0; i<m; i++){
            int task = tasks[i];
            t = max(t, 1ll*i);
            if (pq.size() == 0){
                t = 1ll*nonAvail.top().first;
            }
            while (!nonAvail.empty() && nonAvail.top().first<=t){
                auto cur = nonAvail.top();
                nonAvail.pop();
                pq.emplace(servers[cur.second], cur.second);
            }

            auto cur = pq.top();
            pq.pop();
            res.push_back(cur.second);
            nonAvail.emplace(1ll*t+1ll*task, cur.second);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> servers = {3,3,2}, tasks = {1,2,3,2,1,2};
    vector<int> res = s.assignTasks(servers, tasks);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
