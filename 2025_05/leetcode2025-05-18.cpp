#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> next_;
    unordered_map<long long, int> memo;
    int MOD_NUM;

    int dfs(int i, int j){
        if (i == 0){
            return 1;
        }
        long long key = (long long)i<<32 | j;
        if (memo.count(key)){
            return memo[key];
        }
        int ans = 0;
        for (int k : next_[j]){
            ans = (ans+dfs(i-1, k))%MOD_NUM;
        }
        memo[key] = ans;
        return ans;
    }

public:
    int colorTheGrid(int m, int n) {
        MOD_NUM = 1e9+7;

        vector<int> threePows(m, 1);
        for (int i=1; i<m; i++){
            threePows[i] = threePows[i-1]*3;
        }
        vector<int> valid;
        for (int i=0; i<threePows[m-1]*3; i++){
            bool flag = true;
            for (int j=1; j<m; j++){
                if (i/threePows[j]%3 == i/threePows[j-1]%3){
                    flag = false;
                }
            }
            if (flag){
                valid.push_back(i);
            }
        }

        int validLength = valid.size();
        next_.resize(validLength);
        for (int i=0; i<validLength; i++){
            for (int j=0; j<validLength; j++){
                bool flag = true;
                for (int k : threePows){
                    if (valid[i]/k%3 == valid[j]/k%3){
                        flag = false;
                    }
                }
                if (flag){
                    next_[i].push_back(j);
                }
            }
        }

        int res = 0;
        for (int i=0; i<validLength; i++){
            res = (res+dfs(n-1, i))%MOD_NUM;
        }
        return res;
    }
};

int main(){
    Solution s;
    int m=5, n=5;
    cout << s.colorTheGrid(m, n) << endl;
}
