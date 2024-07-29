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
        // �����������˷ֱ��(0, 0)�㿪ʼ�ߣ��������ߵ�(n-1, n-1)��ʱ���൱��һ������һ������
        // �����һ���˵�λ�ñ�ʾΪ(r1, c1)���ڶ����˵�λ�ñ�ʾΪ(r2, c2)����ô���ǿ���֪����r1+c1 = r2+c2
        // �������֪����k = r1+c1���Լ�r1��r2���Ϳ��Էֱ�õ����˵�λ��
        // ��ô���Ƕ���f[k][r1][r2]Ϊ�������˷ֱ��ߵ�(r1, k-r1)��(r2, k-r2)ʱ�����Բ�ժ�����ٸ�ӣ��
        // ��ˣ����Ƿ��������������ֵ��
        // ����������������λ�õ�ӣ����Ŀ֮��Ϊs(��ʱҪ��֤���߶����ھ�����)
        // 1����ǰ������������һ���������㶼����ƽ�ƶ������Ǵ�ʱf[k][r1][r2] = f[k-1][r1][r2]+s
        // 2����ǰ��һ����������һ����һ��������ƽ�ƶ������ڶ�����������һ���ڶ���������ƽ�ƶ���
        //    ��ô��ʱf[k][r1][r2] = f[k-1][r1][r2-1]+s
        // 3����ǰ��һ����������һ����һ��������ƽ�ƶ������ڶ�����������һ���ڶ���������ƽ�ƶ���
        //    ��ô��ʱf[k][r1][r2] = f[k-1][r1-1][r2]+s
        // 4����ǰ������������һ���������㶼����ƽ�ƶ������Ǵ�ʱf[k][r1][r2] = f[k-1][r1-1][r2-1]+s
        f[0][0][0] = grid[0][0];
        for (int k = 1; k<2*n-1; k++){
            for (int r1 = max(k-n+1, 0); r1<min(k+1, n); r1++){
                int c1 = k-r1;
                if (grid[r1][c1] == -1) continue; // ������ǰ��һ����Ϊ���������
                for (int r2 = r1; r2<min(k+1, n); r2++){
                    int c2 = k-r2;
                    if (grid[r2][c2] == -1) continue; // ������ǰ�ڶ�����Ϊ���������
                    int tmp = f[k-1][r1][r2]; // ���1
                    if (r2 >= 1) tmp = max(tmp, f[k-1][r1][r2-1]); // ���2
                    if (r1 >= 1) tmp = max(tmp, f[k-1][r1-1][r2]); // ���3
                    if (r1 >= 1 && r2 >= 1) tmp = max(tmp, f[k-1][r1-1][r2-1]); // ���4
                    // cout << grid[r1][c1] << endl;
                    // ����������s
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
