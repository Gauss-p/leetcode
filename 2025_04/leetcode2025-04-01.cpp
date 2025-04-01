#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> q;
    unordered_map<int, long long> memo;
    long long dfs(int i){
        if (i >= n){
            return 0;
        }
        if (memo.count(i)){
            return memo[i];
        }
        long long res = max(dfs(i+1), dfs(i+q[i][1]+1)+q[i][0]);
        memo[i] = res;
        return res;
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        q = questions;
        return dfs(0);
    }
};

int main(){
    Solution s;
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    cout << s.mostPoints(questions) << endl;
}
