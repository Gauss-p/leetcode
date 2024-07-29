#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
        // ����ÿһ���㣬֮ǰ��������������ƶ�����ǰ��
        // �������Ƕ���f[r][c1][c2]��ʾ�����������˷ֱ��ߵ�(r,c1)��(r,c2)ʱ����ժ��������ӣ����
        // ��ô���Է־����������������ѭ������ʵ�ֵģ�ÿһ�����������Ӧ��Լ������
        f[0][0][m-1] = grid[0][0]+grid[0][m-1];
        for (int r=1; r<n; r++){
            for (int c1 = 0; c1<m; c1++){
                for (int c2 = c1; c2<m; c2++){
                    int tmp = f[r-1][c1][c2];
                    if (c1 >= 1 && c2 >= 1) tmp = max(tmp, f[r-1][c1-1][c2-1]);
                    if (c1 >= 1) tmp = max(tmp, f[r-1][c1-1][c2]);
                    if (c1 >= 1 && c2 < m-1) tmp = max(tmp, f[r-1][c1-1][c2+1]);
                    if (c2 >= 1) tmp = max(tmp, f[r-1][c1][c2-1]);
                    if (c2 < m-1) tmp = max(tmp, f[r-1][c1][c2+1]);
                    if (c1 < m-1 && c2 >= 1) tmp = max(tmp, f[r-1][c1+1][c2-1]);
                    if (c1 < m-1) tmp = max(tmp, f[r-1][c1+1][c2]);
                    if (c1 < m-1 && c2 < m-1) tmp = max(tmp, f[r-1][c1+1][c2+1]);
                    tmp += grid[r][c1];
                    if (c1 != c2) tmp += grid[r][c2];
                    f[r][c1][c2] = tmp;
                }
            }
        }
        int res = 0;
        for (int c1=0; c1<m; c1++){
            for (int c2=0; c2<m; c2++){
                res = max(res, f[n-1][c1][c2]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    cout << s.cherryPickup(grid) << endl;
}
