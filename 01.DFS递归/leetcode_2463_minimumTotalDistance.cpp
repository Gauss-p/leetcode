#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> Robot;
    vector<vector<int>> Factory;
    unordered_map<long long, long long> memo;
    long long dfs(int i, int j){
        if (j < 0){
            return 0;
        }
        if (i < 0){
            return LLONG_MAX/2;
        }
        long long key = ((long long)i<<32) | j;
        if (memo.count(key)){
            return memo[key];
        }
        long long res = dfs(i-1, j);
        int pos = Factory[i][0], limit = Factory[i][1];
        long long dist = 0;
        for (int k=1; k<=min(j+1, limit); k++){
            dist += abs(Robot[j-k+1]-pos);
            res = min(res, dfs(i-1, j-k)+dist);
        }
        memo[key] = res;
        return res;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        Robot = robot;
        Factory = factory;
        return dfs(factory.size()-1, robot.size()-1);
    }
};

int main(){
    Solution s;
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};
    cout << s.minimumTotalDistance(robot, factory) << endl;
}
