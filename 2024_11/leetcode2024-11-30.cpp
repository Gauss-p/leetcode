#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int one = 0, tot = 0;
        for (auto i : nums){
            if (i < 10){
                one += i;
            }
            tot += i;
        }
        return one*2 != tot;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,5,5,25};
    cout << s.canAliceWin(nums) << endl;
}
