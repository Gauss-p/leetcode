#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int total_num = 51;
    vector<vector<int>> gcds; // 用来打表，存储50以内所有数字的互质数
    vector<vector<int>> g; // 用来建图
    vector<vector<int>> same_val; // 存储同值节点，即same_val[i]存的是节点的值为i的所有节点编号
    vector<int> res;
    vector<int> depth; // 用来存储每一个节点的深度
public:
    void find_gcds(){
        gcds.resize(total_num);
        for (int i=1; i<total_num; i++){
            for (int j=1; j<total_num; j++){
                // 利用gcd内置函数，求i,j的最大公因数，如果所求最大公因数为1，说明i,j互质
                // 符合我们gcds[i]的定义，就把j存入gcds[i]
                if (__gcd(i, j) == 1){
                    gcds[i].push_back(j);
                }
            }
        }
    }

    void dfs(vector<int>& nums, int point, int dep){
        // 每次进入，就先将当前节点的深度设置为传入的dep
        // 因此可以通过判断dep[i]是否为-1来判断节点i是否访问过，不需要另外设置一个visited存储
        depth[point] = dep;
        for (int i : gcds[nums[point]]){
            // 在与当前节点的值互质的所有数中循环，
            // 如果同值节点列表中有存储过与其互质的数字i，那么：
            // 1、如果答案还未保存过；2、如果之前存储的答案深度，比现在求得的答案的深度小
            // 上面任何一个判断成立，就将答案设置为与i同值的最后一个节点，即最深的一个节点
            if (same_val[i].empty()){
                continue;
            }
            int last = same_val[i].back();
            if (res[point] == -1 || depth[res[point]] < depth[last]){
                res[point] = last;
            }
        }
        // 当计算完答案后，在与当前节点对应的值相同的向量中，加入当前节点
        // 接下来进行递归，如果与当前节点相邻的节点没有访问过，就再次进入函数，计算相邻的节点
        // 注意，每次进行重新调用时要将深度+1
        same_val[nums[point]].push_back(point);
        for (int i : g[point]){
            if (depth[i] == -1){
                dfs(nums, i, dep+1);
            }
        }
        // 每次递归完后，要将当前节点从同值节点的向量中弹出，用来还原前一次调用函数时的样子
        // 否则会发生某个节点的子孙被当成它的祖先的现象
        // 会发生这种现象的原因是：计算答案的时候，我们总会选择最深的那一个
        // 所以如果一个节点的子孙和它互质，但没有及时删除的话，在计算时它的子孙就会被当成和它最近的互质的祖先
        same_val[nums[point]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        res.resize(n, -1);
        depth.resize(n, -1);
        g.resize(n);
        same_val.resize(total_num);
        // 用循环建图
        for (auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        find_gcds(); // 计算50以内所有数的互质数
        dfs(nums, 0, 1); // 调用定义的dfs函数计算答案
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
