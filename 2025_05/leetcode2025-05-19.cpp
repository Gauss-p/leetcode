#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];
        if (a+b<=c){
            return "none";
        }
        if (a == b && b == c){
            return "equilateral";
        }
        if (a == b || b == c){
            return "isosceles";
        }
        return "scalene";
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,3,4};
    cout << s.triangleType(nums) << endl;
}
