#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> g;
        // 由于可能有多个坐标对应同一个值，那么对于这道题目来说，我们需要的应该是利用值的大小来计算
        // 所以应该用值作为字典中的key，value就是所有对应值为该值的坐标。这里用g来存储
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                g[mat[i][j]].push_back(make_pair(i, j));
            }
        }
        // 定义两个动态规划数组，分别用来记录行和列所能走的最大步数
        // 单纯对于行来说，如果将每一个行都从小到大排序，那么如果要移动到第x个数，就可以从第一个数开始移动到第x个数，即x步
        // 如果要排序，还需要费一些时间，这里g用map来存储，就可以直接按照key升序排列，也就完成了上面说的排序
        // 同理,对于行来说也可以用相同的方式处理
        vector<int> rowMx(m);
        vector<int> colMx(n);
        int res = 0;
        for (auto &kv : g){
            vector<pair<int, int>> pos = kv.second;
            vector<int> mx;
            // 这里mx用来存储:加上循环到的位置,一共最多能走多少步
            // 等所有的点都更新完了,就可以重新放入行和列的列表中了
            for (auto &[x, y] : pos){
                mx.push_back(max(rowMx[x], colMx[y])+1);
                res = max(res, mx.back()); // 每一次更新完就求一次答案
            }
            for (int i=0; i<pos.size(); i++){
                // 重新放入原列表
                rowMx[pos[i].first] = max(rowMx[pos[i].first], mx[i]);
                colMx[pos[i].second] = max(colMx[pos[i].second], mx[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {{3,1,6},{-9,5,7}};
    cout << s.maxIncreasingCells(mat) << endl;
}
