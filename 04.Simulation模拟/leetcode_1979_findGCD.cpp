#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = 1001, mx = 0;
        for (int i : nums){
            mn = min(mn, i);
            mx = max(mx, i);
        }
        return __gcd(mn, mx);
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,10};
    cout << s.findGCD(nums) << endl;
}
