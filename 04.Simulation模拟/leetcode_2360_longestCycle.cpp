#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        int res = -1;
        int curTime = 1;
        for (int i=0; i<n; i++){
            int startTime = curTime;
            int x = i;
            while (x!=-1 && visited[x]==0){
                visited[x] = curTime;
                x = edges[x];
                curTime++;
            }
            if (x!=-1 && visited[x] >= startTime){
                res = max(res, curTime-visited[x]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> res = {3,3,4,2,3};
    cout << s.longestCycle(res) << endl;
}
