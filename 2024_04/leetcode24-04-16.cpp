#include <iostream>
#include <vector>
#include <functional>
#include <set>
using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> sizes; // �洢ÿ����ͨ��Ĵ�С
        vector<vector<int>> vvi; // �洢ÿ����ͨ���б���Ⱦ�ĵ���
        vector<vector<int>> neibor(n); // �洢ÿ��Ԫ�ص��ھ�
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (graph[i][j] == 1 && i != j){
                    neibor[i].push_back(j); // ���������ͬ�ĵ�֮���бߣ��ʹ���neibor��
                }
            }
        }
        set<int> itl(initial.begin(), initial.end()); // ��������initialת����set������������
        // nums�����洢���е�Ԫ�أ��ڲ���ÿһ����ͨ��ʱ��������ͨ��Ľڵ�����нڵ���ɾ��
        // ���Ƿ������Ǽ����Ҳ�ͬ����ͨ��
        vector<int> nums;
        for (int i=0; i<n; i++){
            nums.push_back(i);
        }
        vector<int> visited(n, 0); // ����ж��Ƿ���ʹ���������������ֹ���ֻ�·��������ѭ����
        function<void(int, int, int)> dfs = [&](int x, int fa, int indx){
            sizes[indx]++; // ��ͨ��Ĵ�С����1
            if (itl.count(x)) vvi[indx].push_back(x); // �����ǰ�ڵ㱻��Ⱦ������vvi[indx]��
            nums.erase(remove(nums.begin(), nums.end(), x), nums.end()); // ��nums��ɾ����ǰ�ڵ�
            // cout << nums.size() << endl;
            visited[x] = 1; // ���Ϊ�ѷ���
            for (int y : neibor[x]){
                if (!visited[y] && y != fa){
                    // ���û�з��ʹ������븸�ײ���ͬ���ſ��Լ�������
                    dfs(y, x, indx);
                }
            }
        };

        int indx = -1;
        // �����ѭ���������������е���ͨ���
        while (nums.size()){
            indx++;
            sizes.resize(indx+2);
            vvi.resize(indx+2);
            dfs(nums[0], -1, indx);
        }
        // ����Ҫ��֤���������и�Ⱦ������������սڵ�������M(initial)��С
        // ��Σ�����ж���ڵ����㣺ɾ�����ܹ������Ľڵ�ͬ���࣬��ô�ͷ�����������Сֵ
        // �����������һ����ͨ����ֻ��һ�����Ը�Ⱦ����ô�����Ѹ�Ⱦ�ĵ�����������С��һ������
        int max_num = 0, res = -1;
        for (int i=0; i<=indx; i++){
            if (vvi[i].size() == 1){
                if (sizes[i] > max_num){
                    max_num = sizes[i];
                    res = vvi[i][0];
                }
                if (sizes[i] == max_num){
                    res = min(res, vvi[i][0]);
                }
            }
        }
        return res == -1 ? *min_element(initial.begin(), initial.end()) : res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> initial = {0, 1};
    cout << s.minMalwareSpread(graph, initial) << endl;
}
