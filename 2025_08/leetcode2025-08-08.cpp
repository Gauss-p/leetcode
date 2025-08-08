#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<long long, double> memo;

    double dfs(int i, int j){
        if (i<=0 && j<=0){
            return 0.5;
        }
        if (i<=0){
            return 1.0;
        }
        if (j<=0){
            return 0.0;
        }
        long long key = (long long) i<<32 | j;
        if (memo.count(key)){
            return memo[key];
        }
        double res = 0.25*(dfs(i-4, j)+dfs(i-3, j-1)+dfs(i-2, j-2)+dfs(i-1, j-3));
        memo[key] = res;
        return res;
    }

public:
    double soupServings(int n) {
        if (n >= 4276){
            return 1;
        }
        return dfs((n+24)/25, (n+24)/25);
    }
};

int main(){
    Solution s;
    int n = 4275;
    cout << s.soupServings(n) << endl;
}
