#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n); // �����洢ÿһ���ڵ�ָ��Ľڵ�
        vector<int> degrees(n); // �����洢ÿһ���ڵ�����
        for (auto &e : edges){
            // ����ͼ���Լ���ȱ�
            int from = e[0], to = e[1];
            g[from].push_back(to);
            degrees[to]++;
        }
        // �����Ϊ0�����нڵ������У����ü�֦�ķ���һȦһȦ���ۼ�����
        queue<int> q;
        for (int i=0; i<n; i++){
            if (degrees[i] == 0){
                q.push(i);
            }
        }
        vector<unordered_set<int>> vvi(n); // ����unordered_set����ȥ��
        while (q.size()){
            // ���[fa, i]��һ�����ڵıߣ�˵��i����������Ӧ����i����֪���ȼ�fa����֪�����ټ���fa
            int fa = q.front();
            q.pop();
            for (int i : g[fa]){
                for (int j : vvi[fa]){
                    vvi[i].insert(j); // fa�������������к��ӵ�����
                }
                vvi[i].insert(fa); // ͬʱfa�Լ�ҲӦ���������к��ӵ�����
                degrees[i]--;
                if (degrees[i] == 0){
                    q.push(i);
                }
            }
        }
        vector<vector<int>> res(n);
        for (int i=0; i<n; i++){
            // ����vvi[i]����ȥ�ص����ȣ��������ս��ֻ��Ҫ���򼴿�
            res[i].insert(res[i].end(), vvi[i].begin(), vvi[i].end());
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    int n = 8;
    vector<vector<int>> res = s.getAncestors(n, edges);
    for (auto &i : res){
        for (auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
