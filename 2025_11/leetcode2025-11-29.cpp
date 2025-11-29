#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int tot = 0;
        for (int& i : nums){
            tot += i;
        }
        return tot%k;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,9,7};
    int k = 5;
    cout << s.minOperations(nums, k) << endl;
}
