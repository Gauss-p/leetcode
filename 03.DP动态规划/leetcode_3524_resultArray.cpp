#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(k, 0));
        vector<long long> res(k, 0);
        for (int i=0; i<n; i++){
            int v = nums[i]%k;
            dp[i+1][v%k] = 1;
            for (int j=0; j<k; j++){
                dp[i+1][j*v%k] += dp[i][j];
            }
            for (int j=0; j<k; j++){
                res[j] += dp[i+1][j];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    vector<long long> res = s.resultArray(nums, k);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
