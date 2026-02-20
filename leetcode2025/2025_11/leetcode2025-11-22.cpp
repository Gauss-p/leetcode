#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int i : nums){
            res += min(3-i%3, i%3);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.minimumOperations(nums) << endl;
}
