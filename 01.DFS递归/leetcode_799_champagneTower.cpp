#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, double> memo;
    double tot;
    double dfs(int i, int j){
        if (i == 0 && j == 0){
            return tot;
        }
        
        int key = i<<10 | j;
        if (memo.count(key)){
            return memo[key];
        }
        double left = j>0 ? max(dfs(i-1, j-1)-1, 0.0)/2.0 : 0.0;
        double right = j<i ? max(dfs(i-1, j)-1, 0.0)/2.0 : 0.0;
        memo[key] = left+right;
        return left+right;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        tot = 1.0*poured;
        return min(dfs(query_row, query_glass), 1.0);
    }
};

int main(){
    Solution s;
    int poured = 2, query_row = 1, query_glass = 1;
    cout << s.champagneTower(poured, query_row, query_glass) << endl;
}
