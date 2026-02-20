#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n+2, 1);
        // 由于题目中规定，对于原数组中最左与最右端元素的处理需要将不存在的那个设置为1
        // 所以定义一个新数组val，存储的是：在nums的左右两边各加一个1
        for (int i=0; i<n; i++){
            val[i+1] = nums[i];
        }
        vector<vector<int>> memo(n+2, vector<int>(n+2, -1));
        // 二维数组memo用来完成记忆化搜索
        function<int(int, int)> solve = [&](int l, int r){
            // 该函数用来计算开区间(l, r)上最大能够获取的硬币数
            // 如果模拟，需要删除，较难。正难则反，我们可以加入气球
            // 每一次加入的气球在(l, r)中，因为是逆向模拟，所以相当于现在只剩下气球l+1, r-1以及待加入的气球
            // 所以如果戳爆待加入气球，将获得的硬币数是val[l]*val[m]*val[r]
            // 方便起见，我们称带加入的气球是气球m
            // 但要保证总硬币数最大，还需要计算(l, m)中最大硬币数以及(m, r)中最大硬币数进行求和
            // 因此就出现了递归，同时为了减少用时，记忆化搜索就要派上用场
            // 如果计算过，直接返回计算好的值即可
            if (l >= r-1) return 0;
            int& res = memo[l][r];
            if (res != -1) return res;
            res = 0;
            for (int m=l+1; m<r; m++){
                int tmp_sum = val[l]*val[m]*val[r];
                tmp_sum += solve(l, m)+solve(m, r);
                res = max(res, tmp_sum);
            }
            return res;
        };
        return solve(0, n+1);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
}
