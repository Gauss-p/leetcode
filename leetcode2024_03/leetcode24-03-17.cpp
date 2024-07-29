#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n, 0); // �洢ÿһ���ڵ�Ķ�
        vector<vector<int>> g(n, vector<int>()); // ��ͼ
        for (auto eg : edges){
            int x = eg[0], y = eg[1];
            degrees[x]++;
            degrees[y]++;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        // ���¿�ʼ���С���֦������
        // �����⵽��һȦһȦ�ؼ�����ֱ�����м�ļ����ڵ㣬��ô����һ���Ƿ��Ϲ���ĸ��ڵ�
        // ����Щ�ڵ�Ϊ���ڵ㣬���ĸ߶ȿ��Ա�֤��С
        // ���һ���ڵ�ƫ�����ģ���ô����Ϊ���ڵ㣬����һ����(���м���ЩΪ������)����
        queue<int> q;
        for (int i=0; i<n; i++){
            if (degrees[i] == 1){
                q.emplace(i);
            }
        }
        vector<int> res = {0};
        while (!q.empty()){
            int n = q.size();
            res.clear();
            for (int i=0; i<n; i++){ 
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                for (int j : g[cur]){
                    degrees[j]--;
                    if (degrees[j] == 1){
                        q.emplace(j);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    // vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    // int n = 4;
    // int ex = [[3,0],[3,1],[3,2],[3,4],[5,4]];
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    int n = 6;
    vector<int> res = s.findMinHeightTrees(n, edges);
    for (int i:res) cout << i << " ";
}
