#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = 1e9;
        for (int i : nums){
            int cur = 0;
            for (auto& c : to_string(i)){
                cur += (c-'0');
            }
            res = min(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,12,13,14};
    cout << s.minElement(nums) << endl;
}
