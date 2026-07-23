#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n<=2) return n;
        return 1<<(32-__builtin_clz(n));
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.uniqueXorTriplets(nums) << endl;
}
