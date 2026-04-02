#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
private:
    int m, n;
    unordered_map<int, int> memo;
    vector<vector<int>> Coins;
    int dfs(int i, int j, int k){
        if (i==m-1 && j==n-1){
            return Coins[i][j] >= 0 ? Coins[i][j] : (k<2 ? 0 : Coins[i][j]);
        }
        if (i>=m || j>=n){
            return INT_MIN/2;
        }
        int key = i<<20 | j<<10 | k;
        if (memo.count(key)){
            return memo[key];
        }
        int res = INT_MIN/2;
        res = max(res, dfs(i+1, j, k)+Coins[i][j]);
        res = max(res, dfs(i, j+1, k)+Coins[i][j]);
        if (Coins[i][j] < 0 && k < 2){
            res = max(res, dfs(i+1, j, k+1));
            res = max(res, dfs(i, j+1, k+1));
        }
        memo[key] = res;
        return res;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        Coins = coins;
        m = coins.size();
        n = coins[0].size();
        return dfs(0, 0, 0);
    }
};

int main(){
    Solution s;
    vector<vector<int>> coins = {{0,1,-1},{1,-2,3},{2,-3,4}};
    cout << s.maximumAmount(coins) << endl;
}
