#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        int res = 0, prod = 9;
        string strN = to_string(n);
        // 首先计算总位数比n小的所有特殊数字的数量，我们可以发现，如果一共有n位，那么n位的特殊数字就一共有9*9*8*7*...*(n-1)，所以可以用一个循环来解决所有数位比n小的特殊数字总数
        int sz = strN.size();
        // 我们用prod计算i+1位的特殊数字总数
        for (int i=0; i<sz-1; i++){
            res += prod;
            prod *= 9-i;
        }
        unordered_map<int, int> memo;
        // 接下来是第二部分的计算，也就是数位和n相同的特殊数字的数量，我们定义dfs，其中有两个参数，第一个mask是用二进制表示的已选前缀有哪些数字，比方说，如果mask=6，也就是二进制为110，就代表已选前缀中有0个0和1个1以及1个2，其中每一位上的1就代表这一位数字有被选中，同时每一位代表数字就是从右往左数第几位再减1
        // 第二个参数是prev_smaller，它表示的是已选前缀是否比n的前缀要小，如果小，就为true，否则为false，该布尔变量用来确定每一位选填数字时的上限，如果比n的前缀小，那么当前位上最大填9，否则最大只能填n对应位置上的数字
        auto dfs = [&](auto&& dfs, int mask, int prev_smaller){
            if (__builtin_popcount(mask) == sz){
                // __builtin_popcount函数用来统计一个数字二进制中1的总个数，如果已选前缀中的1的数量和n的长度相同，就说明此时已经选了一个比n小并且特殊的正数，返回1
                return 1;
            }
            int key = mask<<2 | prev_smaller;
            if (memo.count(key)){
                return memo[key];
            }
            int low_limit, up_limit;
            // 如果当前在填第一位即最高位，那么最小必须是1，否则可以填0
            if (mask == 0){
                low_limit = 1;
            }
            else{
                low_limit = 0;
            }
            // 如果已选前缀小于n的前缀，那么最大填9，否则最大只能是n的对应位置上的数字
            if (prev_smaller){
                up_limit = 9;
            }
            else{
                up_limit = strN[__builtin_popcount(mask)]-'0';
            }
            int ans = 0;
            for (int i=low_limit; i<=up_limit; i++){
                if (((mask >> i)&1) == 0){
                    // 如果之前没有选过数字i，就选它
                    ans += dfs(dfs, mask|(1<<i), prev_smaller|(i<up_limit));
                }
            }
            memo[key] = ans;
            return ans;
        };
        res += dfs(dfs, 0, false);
        return res;
    }
};

int main(){
    Solution s;
    int n = 135;
    cout << s.countSpecialNumbers(n) << endl;
}
