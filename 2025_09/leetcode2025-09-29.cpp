#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
private:
    unordered_map<long long, int> memo;
    vector<int> V;
    int dfs(int i, int j){
        if (i+1 == j){
            return 0;
        }
        int ans = INT_MAX/3;
        long long key = (long long) i<<32 | j;
        if (memo.count(key)){
            return memo[key];
        }
        for (int k=i+1; k<j; k++){
            int cur = dfs(i, k)+dfs(k, j)+V[i]*V[k]*V[j];
            ans = min(ans, cur);
        }
        memo[key] = ans;
        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        V = values;
        return dfs(0, values.size()-1);
    }
};

int main(){
    Solution s;
    vector<int> values = {1,2,3};
    cout << s.minScoreTriangulation(values) << endl;
}
