#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> g;

    int quick_pow(int a, int b, int mod){
        int ans = 1;
        while (b){
            if (b&1){
                ans = (1ll*ans*a)%mod;
            }
            a = (1ll*a*a)%mod;
            b >>= 1;
        }
        return ans;
    }

    int dfs(int x, int pa){
        int ans = 0;
        for (int y : g[x]){
            if (y == pa){
                continue;
            }
            ans = max(ans, 1+dfs(y, x));
        }
        return ans;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        g.resize(n+1);
        for (auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int length = dfs(1, -1);
        return quick_pow(2, length-1, (int)1e9+7);
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{1,2}};
    cout << s.assignEdgeWeights(edges) << endl;
}
