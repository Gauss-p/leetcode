#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        // 对于前k个数，可以直接进行处理，编号加入一个集合中
        // 同时对于出现重复的编号，可以将多余的加入"可删除列表"profit
        // 对于索引为k以后的列表，则判断是否可以与profit中的数字替换，可以替换需要满足以下条件：
        // 1、当前列表的编号在之前没有出现过
        // 2、在前k个列表中有可以替换的列表(即有重复编号的列表)
        // 对于所有元素都进行如上判断以及操作，就可求出最大优雅度
        long long res = 0, sum = 0;
        vector<int> profit;
        set<int> cg;
        sort(items.begin(), items.end(), greater<vector<int>>());
        for (int i=0; i<k; i++){
            if (cg.count(items[i][1])){
                profit.push_back(items[i][0]);
            }
            else{
                cg.insert(items[i][1]);
            }
            sum += items[i][0];
        }
        res = sum + 1ll*cg.size()*cg.size();
        int n = items.size();
        for (int i=k; i<n; i++){
            if (cg.count(items[i][1])) continue;
            if (profit.size() != 0){
                cg.insert(items[i][1]);
                sum -= profit.back();
                sum += items[i][0];
                long long tmp = sum + 1ll*cg.size()*cg.size();
                res = max(res, tmp);
                profit.pop_back();
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> items = {{3,2},{5,1},{10,1}};
    int k = 2;
    cout << s.findMaximumElegance(items, k) << endl;
}
