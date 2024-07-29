#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<vector<pair<int, int>>> g(n);
        // ��ͼ����pair<int, int>�洢��Ӧ�ڵ�ı���Լ������ߵ�Ȩֵ
        for (auto &e : edges){
            int x = e[0], y = e[1];
            g[x].push_back(make_pair(y, e[2]));
            g[y].push_back(make_pair(x, e[2]));
        }
        // ����dfs������������paΪ��ʼ�㣬pa->xΪ����ķ�֧���ж��ٸ��ڵ����Ҫ��
        function<int(int, int, int)> dfs = [&](int x, int pa, int tmp){
            int res = 0;
            // tmp�����洢��ֹ��ǰ�ڵ㣬֮ǰ���бߵ�Ȩֵ֮��Ĩ��signalSpeed��ֵ
            // ���ԣ����tmpΪ0����˵����ǰ�ڵ��Ǻϸ�ڵ�
            if (tmp == 0){
                res++;
            }
            for (auto kv : g[x]){
                if (kv.first != pa){
                    // ��ֹ��ͷ��ȥ�ظ���
                    res += dfs(kv.first, x, (tmp+kv.second)%signalSpeed);
                }
            }
            return res;
        };
        // �����������
        // ��Ϊ���ǿ������,�ӽڵ�i��ʼ,i->kΪ�����ϵ����кϹ�ڵ�,��ô��ѭ�����з���,������ܵĵ����Ŀ
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++){
            int tmp_sum = 0;
            for (auto &kv : g[i]){
                int cur = dfs(kv.first, i, kv.second % signalSpeed);
                ans[i] += tmp_sum*cur; // ��������Ŀ
                tmp_sum += cur;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2}};
    int signalSpeed = 1;
    vector<int> res =  s.countPairsOfConnectableServers(edges, signalSpeed);
    for (auto i : res){
        cout << i << " ";
    }
}
