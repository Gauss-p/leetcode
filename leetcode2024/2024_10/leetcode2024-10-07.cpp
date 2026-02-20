#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 第一种方法是贪心，也就是就着剩下的油能跑到哪里算哪里，然后再加油，相当于我开车的时候每经过一个加油站我就保存下它里面可以加多少油，接下来我继续开，直到发现油量为负值时，我再用刚才经过的所有加油站里面的油往车里面加，因为是贪心，所以肯定是哪个油站可以加的油多就先加哪个油站，这时就用到了之前存储的加油站数据，我们用大根堆存储，这样每次弹出都是最大的油量。但是如果将已经过的所有油站都加空还是不能让油箱里面的油量变成正值，就说明我们无法到达当前位置，这时候就返回-1即可，否则就每一次加油时将答案累加1，最终返回答案即可
        priority_queue<int> pq;
        int n = stations.size();
        int res = 0, prevPosition = 0, fuel = startFuel;
        for (int i=0; i<=n; i++){
            int curPosition = (i<n ? stations[i][0] : target);
            // 当前要行驶到的油站在哪里
            fuel -= curPosition - prevPosition; // 用当前要行驶到的油站距离减去上一个到达的油站距离，就算出了两者中间还要花费多少油
            while (fuel < 0 && !pq.empty()){
                // 加空之前记录的最多油的油站
                fuel += pq.top();
                pq.pop();
                res++;
            }
            if (fuel < 0){
                return -1; // 无法到达
            }
            if (i < n){
                pq.push(stations[i][1]);
                prevPosition = curPosition; // 更新上一次到达的油站位置
            }
        }
        return res;
        // -----------------------------------------------
        // 下面是动态规划，我们定义dp[i]表示加了i次油以后最多能够行驶多远，所以我们可以知道，dp[0]就是最初的油量即startFuel，接下来对于每一个油站都加油，不过区别在于从之前的哪一个油站转移过来，那么dp[j+1]就可以从dp[j]转移过来，当然需要满足dp[j]大于当前油站的距离，如果之前没有一次加油后能行驶到当前油站，说明行程终止
        // 不过还有一点要注意，就是每一次遇到一个油站都要更新前面所有加油次数能行驶的最大距离，但是需要从后往前遍历，因为如果从前往后遍历会出现同一个油站加了两次油的情况
        // 最后遍历整个dp数组，看加几次油就可以行驶超过target的距离，返回次数即可，如果没有就说明需要返回-1
        // int n = stations.size();
        // vector<long long> dp(n+1, 0);
        // dp[0] = startFuel;
        // for (int i=0; i<n; i++){
        //     for (int j=i; j>=0; j--){
        //         if (dp[j] >= stations[i][0]){
        //             dp[j+1] = max(dp[j+1], dp[j]+stations[i][1]);
        //         }
        //     }
        // }
        // for (int i=0; i<=n; i++){
        //     if (dp[i] >= target){
        //         return i;
        //     }
        // }
        // return -1;
    }
};

int main(){
    Solution s;
    int target = 100, startFuel = 10;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    cout << s.minRefuelStops(target, startFuel, stations) << endl;
}
