#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> pa;
    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        // ranges::sort(events, {}, [](auto& e){return e[1];});
        sort(events.begin(), events.end(), [](auto&a, auto&b){
            return a[1]<b[1];
        });
        int mx = events[events.size()-1][1];
        for (int i=0; i<mx+2; i++){
            pa.push_back(i);
        }
        int res = 0;
        for (auto& e : events){
            int start = e[0], end = e[1];
            int x = find(start);
            if (x <= end){
                res++;
                pa[x] = x+1;
            }
        }
        return res;

        // sort(events.begin(), events.end(), [](auto&a, auto&b){
        //     return a[0]<b[0];
        // });
        // int n = events.size();
        // int maxDay = 0;
        // for (auto& e : events){
        //     maxDay = max(maxDay, e[1]);
        // }

        // int res = 0;
        // int j = 0;
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (int i=1; i<=maxDay; i++){
        //     while (j<n && events[j][0]<=i){
        //         pq.push(events[j][1]);
        //         j++;
        //     }
        //     while (!pq.empty() && pq.top()<i){
        //         pq.pop();
        //     }
        //     if (!pq.empty()){
        //         pq.pop();
        //         res++;
        //     }
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> events = {{1,2},{2,3},{3,4}};
    cout << s.maxEvents(events) << endl;
}
