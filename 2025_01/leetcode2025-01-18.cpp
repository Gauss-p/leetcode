#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size(), m = 1<<7;
        vector<vector<vector<bool>>> f(n+10, vector<vector<bool>>(k+10, vector<bool>(m, false)));
        vector<vector<vector<bool>>> g(n+10, vector<vector<bool>>(k+10, vector<bool>(m, false)));

        f[0][0][0] = true;
        for (int i=0; i<n; i++){
            for (int j=0; j<=k; j++){
                for (int x=0; x<m; x++){
                    if (f[i][j][x]){
                        f[i+1][j][x] = true;
                        if (j<k){
                            f[i+1][j+1][x|nums[i]] = true;
                        }
                    }
                }
            }
        }

        g[n+1][0][0] = true;
        for (int i=n+1; i>1; i--){
            for (int j=0; j<=k; j++){
                for (int x=0; x<m; x++){
                    if (g[i][j][x]){
                        g[i-1][j][x] = true;
                        if (j<k){
                            g[i-1][j+1][x|nums[i-2]] = true;
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int i=k; i<=n-k; i++){
            for (int x=0; x<m; x++){
                for (int y=0; y<m; y++){
                    if (f[i][k][x] && g[i+1][k][y]){
                        res = max(res, x^y);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,6,7};
    int k = 1;
    cout << s.maxValue(nums, k) << endl;
}
