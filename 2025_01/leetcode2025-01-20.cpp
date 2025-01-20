#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = 0, dis = INT_MAX;
        for (int i : nums){
            if (abs(i) < dis){
                dis = abs(i);
                res = i;
            }
            else if (abs(i) == dis){
                res = max(res, i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-4,-2,1,4,8};
    cout << s.findClosestNumber(nums) << endl;
}
