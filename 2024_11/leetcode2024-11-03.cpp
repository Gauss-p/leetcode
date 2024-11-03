#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<vector<int>, int> memo;
    int dfs(vector<int>& price, vector<vector<int>>& filterSpecial, vector<int>& tmpNeeds, int n){
        if (memo.count(tmpNeeds)){
            return memo[tmpNeeds]; // 记忆化搜索
        }
        int minCost = 0;
        for (int i=0; i<n; i++){
            // 不选择任何大礼包
            minCost += price[i]*tmpNeeds[i];
        }
        for (auto& fs : filterSpecial){
            vector<int> nextNeeds; // 用来存放：如果选择当前大礼包，那么接下来还需要分别购买每件东西多少件
            for (int i=0; i<n; i++){
                if (fs[i] > tmpNeeds[i]){
                    // 如果选择当前大礼包会使得某一件物品的购买数量超出预期，就不能选择
                    break;
                }
                nextNeeds.push_back(tmpNeeds[i]-fs[i]);
            }
            if (nextNeeds.size() == n){
                // 计算每一种情况的花费的最小值
                minCost = min(minCost, dfs(price, filterSpecial, nextNeeds, n)+fs[n]);
            }
        }
        memo[tmpNeeds] = minCost;
        return minCost;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 首先去除一些没有任何优惠的大礼包，如果说一个大礼包的总价钱竟然比分开买更贵，那么我们就需要把这个大礼包去除，不需要考虑，这样可以减少我们判断的干扰项，接下来用dfs的方法，每一次我们选择一种大礼包，如果这个大礼包符合购买它的条件，那么我们就将所需要的物品件数分别减去大礼包中的对应物品件数，然后再进行进一步计算。这样我们可以将一个问题转化为和原问题相同，但规模更小的子问题。以此类推一直到没有任何大礼包可供选择，这时就算触碰到递归基，开始返回价钱并进行累加。最后用这种思路，把每一种选择大礼包的方案都遍历一遍，取最小值即可
        vector<vector<int>> filterSpecial;
        int n = price.size();
        for (auto sp : special){
            int cnt=0, spCnt=0;
            for (int i=0; i<n; i++){
                cnt += sp[i];
                spCnt += sp[i]*price[i];
            }
            if (cnt > 0 && spCnt > sp[n]){
                // 去除干扰项
                filterSpecial.push_back(sp);
            }
        }
        return dfs(price, filterSpecial, needs, n);
    }
};

int main(){
    Solution s;
    vector<int> price = {2,5};
    vector<vector<int>> special = {{3,0,5},{1,2,10}};
    vector<int> needs = {3,2};
    cout << s.shoppingOffers(price, special, needs) << endl;
}
