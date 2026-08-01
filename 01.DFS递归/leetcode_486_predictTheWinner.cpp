#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> NUMS;
    int dfs(int l, int r, int turn){
        if (l == r){
            return turn*NUMS[l];
        }
        int resL = NUMS[l]*turn+dfs(l+1, r, -turn);
        int resR = NUMS[r]*turn+dfs(l, r-1, -turn);
        return max(resL*turn, resR*turn)*turn;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        NUMS = nums;
        int n = nums.size();
        return dfs(0, n-1, 1) >= 0;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,5,2};
    cout << s.predictTheWinner(nums) << endl;
}
