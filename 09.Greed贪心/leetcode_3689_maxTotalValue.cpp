#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = INT_MAX, mx = 0;
        for (int i : nums){
            mn = min(mn, 1ll*i);
            mx = max(mx, 1ll*i);
        }
        return 1ll*k*(mx-mn);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2};
    int k = 2;
    cout << s.maxTotalValue(nums, k) << endl;
}
