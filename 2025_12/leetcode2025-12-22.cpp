#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        vector<int> dp(n, 1);
        for (int j1=1; j1<n; j1++){
            for (int j2=0; j2<j1; j2++){
                bool flag = true;
                for (int i=0; i<m; i++){
                    if (strs[i][j2] > strs[i][j1]){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    dp[j1] = max(dp[j1], dp[j2]+1);
                }
            }
        }
        return n-*max_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution s;
    vector<string> strs = {"babca","bbazb"};
    cout << s.minDeletionSize(strs) << endl;
}
