#include <iostream>
#include <climits>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        // 对于这道题目，我首先想到DFS，但实际上可以直接暴力搜索
        // 方法是这样的,因为要删除节点,我们可以用0表示删除,用1表示未删除,所以如果按顺序排列,就可以组成2**n种二进制数,所以直接循环,并对二进制数进行判断是否符合标准即可
        // 首先创建邻接矩阵,其次我们编写一个函数进行判断是否符合条件
        // 对于每一种情况,我们需要判断其中最大的路径长度是否超过maxDistance,所以直接循环,将已选中的节点单独存放在新的f中,再两两判断其最大距离即可
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
