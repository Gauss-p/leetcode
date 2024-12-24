#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int i = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int res = 0;

        while (i<n || !pq.empty()){
            if (i<n && apples[i] > 0){
                pq.emplace(days[i]+i, apples[i]);
            }
            while (!pq.empty() && pq.top().first <= i){
                pq.pop();
            }
            if (!pq.empty()){
                int d = pq.top().first, a = pq.top().second;
                pq.pop();
                res++;
                if (a>1){
                    pq.emplace(d, a-1);
                }
            }
            i++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> apples = {1,2,3,5,2};
    vector<int> days = {3,2,1,4,2};
    cout << s.eatenApples(apples, days) << endl;
}
