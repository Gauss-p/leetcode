#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
private:
    int n;
    vector<int> sufSum;
    unordered_map<int, int> memo;
    int dfs(int indx, int m){
        if (indx+2*m >= n){
            return sufSum[indx];
        }
        int key = indx<<10 | m;
        if (memo.count(key)){
            return memo[key];
        }
        int nxt = INT_MAX;
        for (int x=1; x<=2*m; x++){
            nxt = min(nxt, dfs(indx+x, max(x, m)));
        }
        memo[key] = sufSum[indx]-nxt;
        return sufSum[indx]-nxt;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        sufSum.resize(n+1, 0);
        for (int i=n-1; i>=0; i--){
            sufSum[i] = sufSum[i+1]+piles[i];
        }
        return dfs(0, 1);
    }
};

int main(){
    Solution s;
    vector<int> piles = {2,7,9,4,4};
    cout << s.stoneGameII(piles) << endl;
}
