#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        auto cal_sum = [&](int n){
            int res = 0;
            string s = to_string(n);
            for (auto c : s){
                res += c-'0';
            }
            return res;
        };
        int num_sum = 0, pos_sum = 0;
        for (auto i : nums){
            num_sum += i;
            pos_sum += cal_sum(i);
        }
        return abs(num_sum-pos_sum);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,15,6,3};
    cout << s.differenceOfSum(nums) << endl;
}
