#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = 0, tot = 0;
        for (int i : nums){
            mx = max(mx, i);
            tot += i;
        }
        return nums.size()*mx-tot;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3};
    cout << s.minMoves(nums) << endl;
}
