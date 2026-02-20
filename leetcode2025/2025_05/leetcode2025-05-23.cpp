#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    vector<vector<int>> g;
    vector<int> N;
    int K;

    pair<long long, long long> dfs(int x, int pa){
        long long f0 = 0, f1 = INT_MIN;
        for (int y : g[x]){
            if (y == pa){
                continue;
            }
            auto r = dfs(y, x);
            long long r0 = r.first, r1 = r.second;
            long long tmp0 = f0, tmp1 = f1;
            f0 = max(tmp0+r0, tmp1+r1);
            f1 = max(tmp0+r1, tmp1+r0);
        }
        return make_pair(max(f0+N[x], f1+(N[x]^K)), max(f0+(N[x]^K), f1+N[x]));
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        N = nums;
        K = k;
        int n = nums.size();
        g.resize(n);
        for (auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return dfs(0, -1).first;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1};
    int k = 3;
    vector<vector<int>> edges = {{0,1},{0,2}};
    cout << s.maximumValueSum(nums, k, edges) << endl;
}
