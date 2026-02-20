#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // 首先考虑什么时候才能达到最大的按位或值，贪心地想，如果在当前位置之后有一个数字在更高的二进制位上有一个1，那么这个子数组加上这个数字一定能够达到更大的一个按位或值，因此我们可以想到，对于每一个位置，记录从这个位置开始，所有二进制位上出现1的最近的索引
        // 我们还可以用记录各个二进制位出现的最近位置的方式来计算答案，我们倒序遍历，对于当前数字中每一个值为1的二进制位我们都更新该二进制位的最近出现位置位当前位置，这样，对于每一个位置我们都可以直接找到从当前位置开始的所有二进制位上出现1的最近索引
        int n = nums.size();
        vector<int> pos(31, -1);
        vector<int> res(n);
        for (int i=n-1; i>=0; i--){
            int j = i;
            for (int k=0; k<31; k++){
                if ((nums[i]>>k)&1){
                    pos[k] = i;
                }
                else{
                    if (pos[k] != -1){
                        j = max(j, pos[k]);
                    }
                }
            }
            res[i] = j-i+1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,0,2,1,3};
    vector<int> res = s.smallestSubarrays(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
