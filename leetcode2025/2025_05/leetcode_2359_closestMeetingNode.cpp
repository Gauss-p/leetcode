#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    int n;
    vector<int> E;
    vector<int> bfs(int x){
        vector<int> dis(n, INT_MAX);
        int d = 0;
        while (x>=0 && dis[x] == INT_MAX){
            dis[x] = d;
            x = E[x];
            d++;
        }
        return dis;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        E = edges;
        n = edges.size();
        vector<int> d1 = bfs(node1), d2 = bfs(node2);
        int res = -1, tot = INT_MAX;
        for (int i=0; i<n; i++){
            int curMax = max(d1[i], d2[i]);
            if (curMax < tot){
                res = i;
                tot = curMax;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> edges = {2,2,3,-1};
    int node1 = 0, node2 = 1;
    cout << s.closestMeetingNode(edges,node1,node2) << endl;
}
