#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // �����Ŀ�����ö�̬�滮������
        // ����Ŀ���Եó����������cost[i]��������time[i]+1��ǽ����ˢ
        // �������ǽ�cost[i]����һ����Ʒ�ļ�ֵ����time[i]+1���������Ʒ�����
        // ��ô�����Ŀ����Ҫ��������ǰn����Ʒ��ѡ������Ʒ��ʹ�����ǵ�������ڵ���n�����⼸����Ʒ����С��ֵ
        // ����dp[i][j]��ʾ����ǰi����Ʒ��ѡ����������ڵ���j�ļ�����Ʒ���⼸����Ʒ����С��ֵ
        // ��ô����ÿһ��dp[i][j]�����Ƿ�����������ۣ�1.ѡ���i����Ʒ��2.��ѡ���i����Ʒ
        // ����1.�����ǿ��Է������ѡ��i����Ʒ��������ڵ���j
        // ��ô�൱����ǰi-1����Ʒ��ѡ��������ڵ���j-(time[i]+1)�ļ�����Ʒ���ټ��ϵ�ǰ��Ʒ
        // Ҳ����dp[i][j] = dp[i-1][j-(time[i]+1)]
        // ����2.�����ǿ��Է��������ѡ��i����Ʒ�����൱����ǰi-1����Ʒ��ѡ
        // Ҳ����dp[i][j] = dp[i-1][j]
        // ������������������Сֵ��Ҳ�����׼ȷ��dp[i][j]��ֵ��
        // ����dp[i][j]�Ķ��壬����ֻ��Ҫ����dp[n][n]���ɣ�ע�����е��������б䶯
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX/2));
        for (int i=0; i<n; i++){
            // ��ǰ0��ǽ��ѡ�������������Ѷ���0
            dp[i][0] = 0;
        }
        for (int i=1; i<=n; i++){
            for (int j=0; j<=n; j++){
                dp[i][j] = min(dp[i][j], dp[i-1][j]); // ���1.
                dp[i][j] = min(dp[i][j], dp[i-1][max(0, j-time[i-1]-1)]+cost[i-1]); // ���2.
            }
        }
        return dp[n][n];
    }
};

int main(){
    Solution s;
    vector<int> cost = {1,2,3,2}, time = {1,2,3,2};
    cout << s.paintWalls(cost, time) << endl;
}
