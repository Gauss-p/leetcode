#include <iostream>
#include <climits>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        // ���������Ŀ���������뵽DFS����ʵ���Ͽ���ֱ�ӱ�������
        // ������������,��ΪҪɾ���ڵ�,���ǿ�����0��ʾɾ��,��1��ʾδɾ��,���������˳������,�Ϳ������2**n�ֶ�������,����ֱ��ѭ��,���Զ������������ж��Ƿ���ϱ�׼����
        // ���ȴ����ڽӾ���,������Ǳ�дһ�����������ж��Ƿ��������
        // ����ÿһ�����,������Ҫ�ж���������·�������Ƿ񳬹�maxDistance,����ֱ��ѭ��,����ѡ�еĽڵ㵥��������µ�f��,�������ж��������뼴��
        vector<vector<int>> g(n, vector<int>(n, INT_MAX/2));
        for (auto r : roads){
            int x = r[0], y = r[1], w = r[2];
            g[x][y] = min(g[x][y], w);
            g[y][x] = min(g[y][x], w);
        }
        for (int i=0; i<n; i++){
            g[i][i] = 0;
        }
        vector<vector<int>> f(n, vector<int>(n));
        function<int(int)> check = [&](int s){
            for (int i=0; i<n; i++){
                if ((s >> i)& 1){
                    f[i] = g[i];
                }
            }
            for (int k=0; k<n; k++){
                if (((s >> k)&1) == 0) continue;
                for (int i=0; i<n; i++){
                    if (((s >> i)&1) == 0 || f[i][k] == INT_MAX/2){
                        continue;
                    }
                    for (int j=0; j<n; j++){
                        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
                    }
                }
            }
            for (int i=0; i<n; i++){
                if (((s >> i)&1) == 0) continue;
                for (int j=0; j<n; j++){
                    if (((s >> j)&1) == 0) continue;
                    if (f[i][j] > maxDistance){
                        return 0;
                    }
                }
            }
            return 1;
        };
        int res = 0;
        for (int s=0; s<(1<<n); s++){
            res += check(s);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> roads = {{0,1,2},{1,2,10},{0,2,10}};
    int n = 3, maxDistance = 5;
    cout << s.numberOfSets(n, maxDistance, roads) << endl;
}
