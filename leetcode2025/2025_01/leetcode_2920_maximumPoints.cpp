#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
private:
    int K;
    vector<vector<int>> g;
    vector<int> C;
    vector<int> visited;
    unordered_map<long long, int> memo;

    int dfs(int x, int div){
        if (g[x].size() == 0){
            return max(C[x]>>(div+1), (C[x]>>div)-K);
        }
        long long key = (long long)x<<32 | div;
        if (memo.count(key)){
            return memo[key];
        }
        visited[x] = 1;
        int first = C[x]>>(div+1), second = (C[x]>>div)-K;
        for (int& y : g[x]){
            if (visited[y] == 0){
                first += dfs(y, div+1);
                second += dfs(y, div);
            }
        }
        visited[x] = 0;
        memo[key] = max(first, second);
        return max(first, second);
    }
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        if (k == 0){
            int res = 0;
            for (int& i : coins) res += i;
            return res;
        }
        set<int> tmp(coins.begin(), coins.end());
        if (tmp.size() == 1 && coins[0] == k){
            int res = 0;
            for (int i=0; i<coins.size(); i++){
                if (coins[i]>>(i+1) == 0) break;
                res += coins[i]>>(i+1);
            }
            return res;
        }

        int n = edges.size()+1;
        g.resize(n);
        for (auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        visited.resize(n, 0);
        C = coins;
        K = k;
        return max(dfs(0, 0), dfs(0, 1));
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3}};
    vector<int> coins = {10,10,3,3};
    int k = 5;
    cout << s.maximumPoints(edges, coins, k) << endl;
}
