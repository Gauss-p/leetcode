#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int n;
    vector<int> Walls;
    vector<pair<int, int>> rd;
    unordered_map<int, int> memo;
    int dfs(int i, int j){
        if (i<0){
            return 0;
        }
        int key = (i<<2) | j;
        if (memo.count(key)){
            return memo[key];
        }
        auto cur = rd[i];
        int x = cur.first, d = cur.second;
        int left = x-d;
        if (i > 0){
            left = max(left, rd[i-1].first+1);
        }
        int l = lower_bound(Walls.begin(), Walls.end(), left)-Walls.begin();
        int r = upper_bound(Walls.begin(), Walls.end(), x)-Walls.begin();
        int resLeft = dfs(i-1, 0)+r-l;

        int right = x+d;
        if (i+1 < n){
            if (j == 0){
                right = min(right, rd[i+1].first-rd[i+1].second-1);
            }
            else{
                right = min(right, rd[i+1].first-1);
            }
        }
        l = lower_bound(Walls.begin(), Walls.end(), x)-Walls.begin();
        r = upper_bound(Walls.begin(), Walls.end(), right)-Walls.begin();
        int resRight = dfs(i-1, 1)+r-l;
        memo[key] = max(resLeft, resRight);
        return max(resLeft, resRight);
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        for (int i=0; i<n; i++){
            rd.push_back(make_pair(robots[i], distance[i]));
        }
        sort(rd.begin(), rd.end());
        Walls = walls;
        sort(Walls.begin(), Walls.end());
        return dfs(n-1, 1);
    }
};

int main(){
    Solution s;
    vector<int> robots = {4}, distance = {3}, walls = {1,10};
    cout << s.maxWalls(robots, distance, walls) << endl;
}
