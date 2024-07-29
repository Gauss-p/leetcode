#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int total_num = 51;
    vector<vector<int>> gcds; // ��������洢50�����������ֵĻ�����
    vector<vector<int>> g; // ������ͼ
    vector<vector<int>> same_val; // �洢ֵͬ�ڵ㣬��same_val[i]����ǽڵ��ֵΪi�����нڵ���
    vector<int> res;
    vector<int> depth; // �����洢ÿһ���ڵ�����
public:
    void find_gcds(){
        gcds.resize(total_num);
        for (int i=1; i<total_num; i++){
            for (int j=1; j<total_num; j++){
                // ����gcd���ú�������i,j�������������������������Ϊ1��˵��i,j����
                // ��������gcds[i]�Ķ��壬�Ͱ�j����gcds[i]
                if (__gcd(i, j) == 1){
                    gcds[i].push_back(j);
                }
            }
        }
    }

    void dfs(vector<int>& nums, int point, int dep){
        // ÿ�ν��룬���Ƚ���ǰ�ڵ���������Ϊ�����dep
        // ��˿���ͨ���ж�dep[i]�Ƿ�Ϊ-1���жϽڵ�i�Ƿ���ʹ�������Ҫ��������һ��visited�洢
        depth[point] = dep;
        for (int i : gcds[nums[point]]){
            // ���뵱ǰ�ڵ��ֵ���ʵ���������ѭ����
            // ���ֵͬ�ڵ��б����д洢�����以�ʵ�����i����ô��
            // 1������𰸻�δ�������2�����֮ǰ�洢�Ĵ���ȣ���������õĴ𰸵����С
            // �����κ�һ���жϳ������ͽ�������Ϊ��iֵͬ�����һ���ڵ㣬�������һ���ڵ�
            if (same_val[i].empty()){
                continue;
            }
            int last = same_val[i].back();
            if (res[point] == -1 || depth[res[point]] < depth[last]){
                res[point] = last;
            }
        }
        // ��������𰸺����뵱ǰ�ڵ��Ӧ��ֵ��ͬ�������У����뵱ǰ�ڵ�
        // ���������еݹ飬����뵱ǰ�ڵ����ڵĽڵ�û�з��ʹ������ٴν��뺯�����������ڵĽڵ�
        // ע�⣬ÿ�ν������µ���ʱҪ�����+1
        same_val[nums[point]].push_back(point);
        for (int i : g[point]){
            if (depth[i] == -1){
                dfs(nums, i, dep+1);
            }
        }
        // ÿ�εݹ����Ҫ����ǰ�ڵ��ֵͬ�ڵ�������е�����������ԭǰһ�ε��ú���ʱ������
        // ����ᷢ��ĳ���ڵ�����ﱻ�����������ȵ�����
        // �ᷢ�����������ԭ���ǣ�����𰸵�ʱ�������ܻ�ѡ���������һ��
        // �������һ���ڵ������������ʣ���û�м�ʱɾ���Ļ����ڼ���ʱ��������ͻᱻ���ɺ�������Ļ��ʵ�����
        same_val[nums[point]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        res.resize(n, -1);
        depth.resize(n, -1);
        g.resize(n);
        same_val.resize(total_num);
        // ��ѭ����ͼ
        for (auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        find_gcds(); // ����50�����������Ļ�����
        dfs(nums, 0, 1); // ���ö����dfs���������
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,3,2};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3}};
    vector<int> res = s.getCoprimes(nums, edges);
    for (auto &i : res){
        cout << i << " ";
    }
    // unordered_map<string, int> g;
    // g["1-2"] = g["1-2"] ? 2 : 3;
    // cout << g["1-2"] << endl;
}
