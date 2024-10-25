#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // 这道题目用dfs算法解决，定义dfs(x)表示:当初始值为x时经过一系列挑选，最大的总奖励是多少，所以，最终返回值就是dfs(0)，而这里排序是方便后面的二分查找下一个可以被选的数字
        sort(rewardValues.begin(), rewardValues.end());
        unordered_map<int, int> memo;
        function<int(int)> dfs = [&](int x){
            if (memo.count(x)){
                return memo[x];
            }
            int it = upper_bound(rewardValues.begin(), rewardValues.end(), x)-rewardValues.begin();//该值表示在原数组里面最接近初始奖励值并且比初始奖励值大的那个值的索引，也就是说，在当前索引之后的所有值都可以被选择
            int ans = 0;
            for (int i=it; i<rewardValues.size(); i++){
                ans = max(ans, rewardValues[i]+dfs(x+rewardValues[i]));// 计算最大值
            }
            memo[x] = ans;
            return ans;
        };
        return dfs(0);
    }
};

int main(){
    Solution s;
    vector<int> rewardValues = {1,6,4,3,2};
    cout << s.maxTotalReward(rewardValues) << endl;
}
