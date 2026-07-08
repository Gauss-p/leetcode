#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    int modNum;
    int quickPow(int a, int b){
        int ans = 1;
        long long base = a;
        while (b){
            if (b&1){
                ans = (ans*base)%modNum;
            }
            base = (base*base)%modNum;
            b >>= 1;
        }
        return ans;
    }
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        modNum = 1e9+7;
        int n = s.size();
        vector<int> pos;
        vector<int> preSum(n+1, 0);
        vector<int> nums = {0};
        for (int i=0; i<n; i++){
            preSum[i+1] = preSum[i]+(s[i]-'0');
            if (s[i] != '0'){
                nums.push_back((1ll*nums.back()*10+1ll*(s[i]-'0'))%modNum);
                pos.push_back(i);
            }
        }

        vector<int> res;
        for (auto& q : queries){
            int l = q[0], r = q[1];
            int il = lower_bound(pos.begin(), pos.end(), l)-pos.begin();
            int ir = upper_bound(pos.begin(), pos.end(), r)-pos.begin();
            int cur = (1ll*nums[ir]-1ll*nums[il]*quickPow(10, ir-il))%modNum;
            cur = (cur+modNum)%modNum;
            res.push_back(1ll*cur*(preSum[r+1]-preSum[l])%modNum);
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "10203004";
    vector<vector<int>> queries = {{0,7},{1,3},{4,6}};
    vector<int> res = sl.sumAndMultiply(s, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
