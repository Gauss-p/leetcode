#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    string S1, S2;
    int m, n;
    unordered_map<int, int> memo;
    int dfs(int i, int j){
        if (i == m || j == n){
            return 0;
        }
        int key = i<<10 | j;
        if (memo.count(key)){
            return memo[key];
        }
        int res1 = dfs(i+1, j);
        int res2 = dfs(i, j+1);
        int res3 = 0;
        if (S1[i] == S2[j]){
            res3 = 2*S1[i]+dfs(i+1, j+1);
        }
        return memo[key] = max(res1, max(res2, res3));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        S1 = s1;
        S2 = s2;
        m = s1.size();
        n = s2.size();
        int tot = 0;
        for (auto& i : s1+s2){
            tot += i;
        }
        return tot-dfs(0, 0);
    }
};

int main(){
    Solution s;
    string s1 = "sea", s2 = "eat";
    cout << s.minimumDeleteSum(s1, s2) << endl;
}
