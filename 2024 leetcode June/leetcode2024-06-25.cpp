#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        // ���������Ŀ������������Ҫ֤�����Ӽ�ֻ��һ�л������е����
        // ����ͨ������������������Ŀ�жԺ��Ӽ��Ķ��壬֤�������û��С�����еĽ⣬��û�д��ڻ�������еĽ�
        // ����Ϊ���еĽ����ת�������еĽ⣬����ֻ��Ҫ����һ�С������Լ��޽��������
        // ��Ϊÿһ�ж�ֻ��0��1�����Կ���ת���ɶ�������������Ϊ����̫�࣬�ͽ���ȥ�ز���
        // ������ж�Ӧ�Ķ���������λ��Ľ��Ϊ0���𰸾���������
        // ��Ȼ�������һ����ȫ��0���ͷ�����һ�У����򷵻�[]
        // ע�⣬���ص��±�Ҫ����������
        unordered_map<int, int> mp;
        int n = grid.size();
        for (int i=0; i<n; i++){
            int tmp = 0;
            for (int j=0; j<(int)grid[i].size(); j++){
                tmp |= grid[i][j] << j;
            }
            if (tmp == 0){
                return {i};
            }
            mp[tmp] = i;
        }
        for (auto &kv : mp){
            for (auto &kv2 : mp){
                int tmp1 = kv.first, tmp2 = kv2.first;
                int indx1 = kv.second, indx2 = kv2.second;
                if ((tmp1 & tmp2) == 0){
                    if (indx1 > indx2) return {indx2, indx1};
                    else return {indx1, indx2};
                }
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,1,0},{0,0,0,1},{1,1,1,1}};
    vector<int> res = s.goodSubsetofBinaryMatrix(grid);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
