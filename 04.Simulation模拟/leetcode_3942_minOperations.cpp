#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 由于在循环视角下，nums一定是要么递增要么递减才能最终将它通过操作变成递增顺序，因此先找到分界点0的位置，根据前后值的大小关系，确定nums究竟是递增还是递减，最后直接计算操作次数即可
        int n = nums.size();
        bool inc = true, dec = true;
        int pos = find(nums.begin(), nums.end(), 0)-nums.begin();
        for (int i=1; i<n; i++){
            int cur = nums[(pos+i)%n];
            if (cur != i){
                inc = false;
            }
            if (cur != n-i){
                dec = false;
            }

            if ((!inc) && (!dec)){
                return -1;
            }
        }
        if (inc){
            return min(pos, n-pos+2);
        }
        return min(pos+2, n-pos);
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,2,1};
    cout << s.minOperations(nums) << endl;
}
