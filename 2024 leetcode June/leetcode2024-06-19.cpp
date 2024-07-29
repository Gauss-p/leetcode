#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> g;
        // ���ڿ����ж�������Ӧͬһ��ֵ����ô���������Ŀ��˵��������Ҫ��Ӧ��������ֵ�Ĵ�С������
        // ����Ӧ����ֵ��Ϊ�ֵ��е�key��value�������ж�ӦֵΪ��ֵ�����ꡣ������g���洢
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                g[mat[i][j]].push_back(make_pair(i, j));
            }
        }
        // ����������̬�滮���飬�ֱ�������¼�к��������ߵ������
        // ������������˵�������ÿһ���ж���С����������ô���Ҫ�ƶ�����x�������Ϳ��Դӵ�һ������ʼ�ƶ�����x��������x��
        // ���Ҫ���򣬻���Ҫ��һЩʱ�䣬����g��map���洢���Ϳ���ֱ�Ӱ���key�������У�Ҳ�����������˵������
        // ͬ��,��������˵Ҳ��������ͬ�ķ�ʽ����
        vector<int> rowMx(m);
        vector<int> colMx(n);
        int res = 0;
        for (auto &kv : g){
            vector<pair<int, int>> pos = kv.second;
            vector<int> mx;
            // ����mx�����洢:����ѭ������λ��,һ��������߶��ٲ�
            // �����еĵ㶼��������,�Ϳ������·����к��е��б�����
            for (auto &[x, y] : pos){
                mx.push_back(max(rowMx[x], colMx[y])+1);
                res = max(res, mx.back()); // ÿһ�θ��������һ�δ�
            }
            for (int i=0; i<pos.size(); i++){
                // ���·���ԭ�б�
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
