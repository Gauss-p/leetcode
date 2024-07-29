#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(2*n-1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        // 假设有两个人分别从(0, 0)点开始走，这样都走到(n-1, n-1)点时就相当于一个人走一个来回
        // 假设第一个人的位置表示为(r1, c1)，第二个人的位置表示为(r2, c2)，那么我们可以知道：r1+c1 = r2+c2
        // 所以如果知道了k = r1+c1，以及r1、r2，就可以分别得到两人的位置
        // 那么我们定义f[k][r1][r2]为：两个人分别走到(r1, k-r1)和(r2, k-r2)时最多可以采摘到多少个樱桃
        // 因此，我们分四种情况进行求值：
        // 我们设两个人所在位置的樱桃数目之和为s(此时要保证两者都不在荆棘区)
        // 1、当前两个点是由上一步的两个点都向右平移而来，那此时f[k][r1][r2] = f[k-1][r1][r2]+s
        // 2、当前第一个点是由上一步第一个点向右平移而来，第二个点是由上一步第二个点向下平移而来
        //    那么此时f[k][r1][r2] = f[k-1][r1][r2-1]+s
        // 3、当前第一个点是由上一步第一个点向下平移而来，第二个点是由上一步第二个点向右平移而来
        //    那么此时f[k][r1][r2] = f[k-1][r1-1][r2]+s
        // 4、当前两个点是由上一步的两个点都向右平移而来，那此时f[k][r1][r2] = f[k-1][r1-1][r2-1]+s
        f[0][0][0] = grid[0][0];
        for (int k = 1; k<2*n-1; k++){
            for (int r1 = max(k-n+1, 0); r1<min(k+1, n); r1++){
                int c1 = k-r1;
                if (grid[r1][c1] == -1) continue; // 跳过当前第一个点为荆棘的情况
                for (int r2 = r1; r2<min(k+1, n); r2++){
                    int c2 = k-r2;
                    if (grid[r2][c2] == -1) continue; // 跳过当前第二个点为荆棘的情况
                    int tmp = f[k-1][r1][r2]; // 情况1
                    if (r2 >= 1) tmp = max(tmp, f[k-1][r1][r2-1]); // 情况2
                    if (r1 >= 1) tmp = max(tmp, f[k-1][r1-1][r2]); // 情况3
                    if (r1 >= 1 && r2 >= 1) tmp = max(tmp, f[k-1][r1-1][r2-1]); // 情况4
                    // cout << grid[r1][c1] << endl;
                    // 接下来计算s
                    tmp += grid[r1][c1];
                    if (r1 != r2){
                        tmp += grid[r2][c2];
                    }
                    f[k][r1][r2] = tmp;
                }
            }
        }
        return max(f[2*n-2][n-1][n-1], 0);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    cout << s.cherryPickup(grid) << endl;
}
