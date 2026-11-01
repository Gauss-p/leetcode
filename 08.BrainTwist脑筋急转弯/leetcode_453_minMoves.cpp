#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int i : nums){
            res += i-mn;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.minMoves(nums) << endl;
}
