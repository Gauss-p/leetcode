#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [&](auto&a, auto&b){
            return abs(a)>abs(b);
        });
        long long res = 0;
        for (int i=0; i<(n+1)/2; i++){
            res += 1ll*nums[i]*nums[i];
        }
        for (int i=(n+1)/2; i<n; i++){
            res -= 1ll*nums[i]*nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.maxAlternatingSum(nums) << endl;
}
