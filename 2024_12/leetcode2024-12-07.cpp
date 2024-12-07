#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    unordered_map<long long, double> memo;
    // 定义dfs(step, x, y)返回移动step次后仍然在棋盘内的方案总数
    double dfs(int step, int x, int y, int k, int n){
        if (step == k){
            return 1;
        }
        long long key = (long long)step << 32 | (long long)x << 16 | y;
        if (memo.count(key)){
            return memo[key];
        }
        double res = 0;
        for (auto&d : dirs){
            int dx = d[0], dy = d[1];
            if (x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<n){
                res += dfs(step+1, x+dx, y+dy, k, n);
            }
        }
        memo[key] = res;
        return res;
    }
public:
    double knightProbability(int n, int k, int r, int c) {
        double inside = dfs(0, r, c, k, n);
        for (int i=0; i<k; i++){
            inside /= 8.0;
        }
        return inside;
    }
};

int main(){
    Solution s;
    int n = 3, k = 2, r = 0, c = 0;
    cout << s.knightProbability(n, k, r, c) << endl;
}
