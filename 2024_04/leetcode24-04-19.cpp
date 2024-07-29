class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hours) {
        long long need_save = 0;
        int n = dist.size();
        for (int i : dist){
            need_save += i;
        }
        // �������������Ϣʱ�仹�޷��ڹ涨ʱ���ڵ���Ļ�������-1
        if (need_save > 1ll*speed*hours) return -1;
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, INT_MAX));
        // ����dp��ʹ��dp[i][j]��ʾǰi��·������j����Ϣʱ�������ѵ���Сʱ��
        for (int i=0; i<=n; i++){
            // ǰ0��·�����������Σ�ʱ�䶼��0
            dp[0][i] = 0;
        }
        for (int i=1; i<=n; i++){
            // ǰi��·��0��,���ѵ�ʱ�����sum(dist[0], dist[i-1])
            dp[i][0] = dp[i-1][0]+dist[i-1];
            dp[i][0] += (speed - dp[i][0]%speed)%speed;
            for (int j=1; j<=i; j++){
                long long tmp = dp[i-1][j]+dist[i-1];
                tmp += (speed - tmp%speed)%speed; // ��������i��·��Ϣʱ�������������ѵ���Сʱ��
                dp[i][j] = min(tmp, dp[i-1][j-1]+dist[i-1]); // ���i��·������Ϣʱ��ʱ���ѵ���Сʱ������С
            }
        }
        long long target = 1ll*hours*speed-dist[n-1];
        for (int j=0; j<n; j++){
            // ���ǰn-1��·,����j����Ϣʱ�����Сʱ�䲻�����涨ʱ��,�ͷ���j����Сֵ,���򷵻�-1
            if (dp[n-1][j] <= target){
                return j;
            }
        }
        return -1;
    }
};
