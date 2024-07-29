#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        int pric[m+1][n+1]; // �����洢��i��j��ľ��ļ�ֵ
        memset(pric, 0, sizeof(pric));
        long long dp[m+1][n+1];
        // ���ǳ����½�Ϊ(i��j�еķ���)�����Ͻ�Ϊ(��ľ������Ͻ�)�ķ�ľ��Ϊ"��ľ��"
        // �����洢��ľ������ֵ
        for (auto &p : prices){
            pric[p[0]][p[1]] = p[2]; // �����p[0]��p[1]��ľ��ļ�ֵ
        }
        for (int i=1; i<=m; i++){
            for (int j=0; j<=n; j++){
                long long tmp = 0;
                // ��ô��ľ��ļ�ֵ��Ϊ��
                // 1.�Դ����ҵ�k��С������ұ�Ե(�����±�Ե)�п���ľ��
                // 2.�������ֵ�����ұ�����ֵ(�������������)����Ϊ��ľ��ļ�ֵ
                // 3.ѭ��k���Ϳ��������ľ�����ļ�ֵ
                for (int k=1; k<j; k++){
                    // ��ѭ��������
                    tmp = max(tmp, dp[i][k]+dp[i][j-k]);
                }
                for (int k=1; k<i; k++){
                    // ��ѭ�����ϵ���
                    tmp = max(tmp, dp[k][j]+dp[i-k][j]);
                }
                // �����ľ��ļ�ֵ��prices��������ֱ�Ӹ�������ô�������tmp��ȡ���ֵ����
                dp[i][j] = max(1ll*pric[i][j], tmp);
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;
    // int m = 3, n = 5;
    // vector<vector<int>> prices = {{1,4,2},{2,2,7},{2,1,3}};
    int m = 4, n = 6;
    vector<vector<int>> prices = {{3,2,10},{1,4,2},{4,1,3}};
    cout << s.sellingWood(m, n, prices);
}
