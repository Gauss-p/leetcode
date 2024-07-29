#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        // 首先从小到大排序
        sort(coins.begin(), coins.end());
        // 定义maxest_num，使得可以取得的金额用区间表示为[1, maxest_num)
        int maxest_num = 1, res = 0;
        int indx = 0, n = coins.size();
        while (maxest_num <= target){
            // 由于maxest_num是无法取到的，所以判断条件中应当把等于的情况也算上
            if (indx < n && coins[indx] <= maxest_num){
                // 如果当前循环到的硬币没有突破之前的区间
                // 那么可以将区间向后延长至(maxest_num+当前额度)
                // 理由是之前小于maxest_num的额度都可以渠道，那么只需要从(maxest_num-当前额度)开始
                // 到之后每一个额度都加上当前额度，就可以把区间延长至(maxest_num+当前额度)
                maxest_num += coins[indx];
                indx++;
            }
            else{
                // 如果断开，那么可以加上一个硬币，它的额度比之前可以取到的最大额度大1
                // 这样可以保证能够向后延伸得最长，即可以保证所添加的数量最少
                maxest_num = maxest_num*2;
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,4,10,5,7,19};
    int target = 20;
    cout << s.minimumAddedCoins(coins, target) << endl;
}
