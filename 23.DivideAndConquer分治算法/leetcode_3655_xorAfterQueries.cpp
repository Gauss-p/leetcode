#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
    long long quick_pow(long long a, int b, int modNum){
        long long ans = 1;
        while (b){
            if (b&1){
                ans = (ans*a)%modNum;
            }
            a = (a*a)%modNum;
            b >>= 1;
        }
        return ans;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int modNum = 1e9+7;
        int n = nums.size();
        int B = sqrt((int)queries.size());
        vector<vector<long long>> diff(B);

        for (auto&q : queries){
            int l=q[0], r=q[1], k=q[2], v=q[3];
            if (k>=B){
                for (int i=l; i<=r; i+=k){
                    nums[i] = (1ll*nums[i]*v)%modNum;
                }
                continue;
            }

            if (diff[k].empty()){
                diff[k] = vector<long long>(n+k, 1);
            }
            diff[k][l] = (diff[k][l]*v)%modNum;
            int right = r-(r-l)%k+k;
            diff[k][right] = (diff[k][right]*(quick_pow(v, modNum-2, modNum)))%modNum;
        }

        for (int k=0; k<B; k++){
            vector<long long> d = diff[k];
            if (d.empty()){
                continue;
            }

            for (int start=0; start<k; start++){
                long long prod = 1;
                for (int i=start; i<n; i+=k){
                    prod = (prod*d[i])%modNum;
                    nums[i] = (nums[i]*prod)%modNum;
                }
            }
        }

        int res = 0;
        for (int i : nums){
            res ^= i;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1};
    vector<vector<int>> queries = {{0,2,1,4}};
    cout << s.xorAfterQueries(nums, queries) << endl;
}
