#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        if (arrival.size() <= k){
            vector<int> res;
            for (int i=0; i<arrival.size(); i++){
                res.push_back(i);
            }
            return res;
        }
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        for (int i=0; i<k; i++){
            free.push(i);
        }
        vector<int> cnt(k, 0);
        int mxCnt = 0;
        vector<int> res;
        for (int i=0; i<arrival.size(); i++){
            int t = arrival[i], l = load[i];
            while (busy.size() && busy.top().first <= t){
                auto cur = busy.top();
                busy.pop();
                free.push(i+((cur.second-i)%k+k)%k);
            }

            if (free.size() == 0){
                continue;
            }

            int j = free.top()%k;
            free.pop();
            busy.emplace(t+l, j);
            cnt[j]++;

            if (cnt[j] > mxCnt){
                mxCnt = cnt[j];
                res = {j};
            }
            else if (cnt[j] == mxCnt){
                res.push_back(j);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int k = 3;
    vector<int> arrival = {1,2,3,4,5}, load = {5,2,3,3,3};
    vector<int> res = s.busiestServers(k, arrival, load);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
