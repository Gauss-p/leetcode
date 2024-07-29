#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mn = 0;
        // mn��Ϊ�򻯵�dp[i][j]�������洢�ӵ�ǰ�����ߵ����½ǵĸ�����Ҫ���ٲ�
        vector<vector<pair<int, int>>> col_stacks(n);
        // col_stacks�����洢ÿһ�е�����
        // ����pair��ǰһ��int����ǰ����Ӧ�����ݣ���һ��int����ǰ�ڼ���
        vector<pair<int, int>> row_st;
        // row_st�����洢ÿһ�е����ݣ����ʽ��col_stacks[i]����
        // �����row_st����Ҫ���ģ�ش洢��ֻ��Ҫÿһ�й�������
        for (int i=m-1; i>=0; i--){
            row_st.clear();
            for (int j=n-1; j>=0; j--){
                int g = grid[i][j]; // ȡ����ǰ���������ֵ��������д
                auto &col_st = col_stacks[j]; // ͬʱȡ����ǰ�е����ݣ���Ϊ��Ҫ�޸ģ����Բ�������ȡֵ
                // ��grid[i][j]���������½ǵĸ���ʱ��ֻ��Ҫһ���Ϳ��Ե������½�
                // ��˵�grid[i][j]ָ��grid[m-1][n-1]ʱ���ͽ�mn��ʼ��Ϊ1�������ʼ��Ϊ�����
                if (i==m-1 && j==n-1){
                    mn = 1;
                }
                else{
                    mn = INT_MAX;
                }
                if (g > 0){
                    // ��g������ʱ���ſ������һ������ƶ������ԣ�ֻ��Ҫ�ڹ涨�ķ�Χ��Ѱ����С��һ��������
                    // Ѱ����С����������lower_bound����
                    // lower_boundԭ��������Ѱ�ҵ�һ������n������, ��ʱֻ��Ҫ���������Զ���һ�������Ϳ�������ʵ����Ҫ�Ĺ���
                    // ��һ������������Ѱ��,ֻҪ�ҵ���С���ƶ�����,����Ϊ��ǰ���ӵ�Ѱ�ҵĸ���ֻ��Ҫһ��
                    // ����ÿ��Ѱ�ҵ�,�ͼ�1������С����
                    auto it = lower_bound(col_st.begin(), col_st.end(), i+g, [](const auto &a, const int b){
                        return a.second > b;
                    });
                    if (it < col_st.end()){
                        mn = it->first+1;
                    }
                    // ��������Ѱ��
                    it = lower_bound(row_st.begin(), row_st.end(), j+g, [](const auto &a, const int b){
                        return a.second > b;
                    });
                    if (it < row_st.end()){
                        mn = min(mn, it->first+1);
                    }
                }

                if (mn < INT_MAX){
                    // ��Ѱ�ҵ��Ժ�,Ϊ��ά�������еĵ�����(����Ϊ����lower_bound���ֲ���),��Ҫ��С��mn��ȫ������
                    while (!row_st.empty() && mn < row_st.back().first){
                        row_st.pop_back();
                    }
                    row_st.emplace_back(mn, j);

                    while (!col_st.empty() && mn < col_st.back().first){
                        col_st.pop_back();
                    }
                    col_st.emplace_back(mn, i);
                }
            }
        }
        // ��������ҵ�����ô����mn,���򷵻�-1
        return mn<INT_MAX ? mn : -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
    cout << s.minimumVisitedCells(grid) << endl;
}
