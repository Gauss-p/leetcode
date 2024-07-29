class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hours) {
        long long need_save = 0;
        int n = dist.size();
        for (int i : dist){
            need_save += i;
        }
        // 如果跳过所有休息时间还无法在规定时间内到达的话，返回-1
        if (need_save > 1ll*speed*hours) return -1;
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, INT_MAX));
        // 定义dp，使得dp[i][j]表示前i条路中跳过j次休息时间所花费的最小时间
        for (int i=0; i<=n; i++){
            // 前0条路无论跳过几次，时间都是0
            dp[0][i] = 0;
        }
        for (int i=1; i<=n; i++){
            // 前i条路跳0次,花费的时间就是sum(dist[0], dist[i-1])
            dp[i][0] = dp[i-1][0]+dist[i-1];
            dp[i][0] += (speed - dp[i][0]%speed)%speed;
            for (int j=1; j<=i; j++){
                long long tmp = dp[i-1][j]+dist[i-1];
                tmp += (speed - tmp%speed)%speed; // 不跳过第i条路休息时间的情况下所花费的最小时间
                dp[i][j] = min(tmp, dp[i-1][j-1]+dist[i-1]); // 与第i条路跳过休息时间时花费的最小时间求最小
            }
        }
        long long target = 1ll*hours*speed-dist[n-1];
        for (int j=0; j<n; j++){
            // 如果前n-1条路,跳过j次休息时间的最小时间不超过规定时间,就返回j的最小值,否则返回-1
            if (dp[n-1][j] <= target){
                return j;
            }
        }
        return -1;
    }
};
