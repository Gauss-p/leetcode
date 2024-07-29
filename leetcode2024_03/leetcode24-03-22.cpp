#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mn = 0;
        // mn即为简化的dp[i][j]，用来存储从当前格子走到右下角的格子需要多少步
        vector<vector<pair<int, int>>> col_stacks(n);
        // col_stacks用来存储每一列的数据
        // 其中pair的前一个int代表当前所对应的数据，后一个int代表当前第几行
        vector<pair<int, int>> row_st;
        // row_st用来存储每一行的数据，其格式与col_stacks[i]类似
        // 这里的row_st不需要大规模地存储，只需要每一行滚动即可
        for (int i=m-1; i>=0; i--){
            row_st.clear();
            for (int j=n-1; j>=0; j--){
                int g = grid[i][j]; // 取出当前格子里的数值，方便书写
                auto &col_st = col_stacks[j]; // 同时取出当前列的数据，因为需要修改，所以采用引用取值
                // 当grid[i][j]代表最右下角的格子时，只需要一步就可以到达右下角
                // 因此当grid[i][j]指向grid[m-1][n-1]时，就将mn初始化为1，否则初始化为无穷大
                if (i==m-1 && j==n-1){
                    mn = 1;
                }
                else{
                    mn = INT_MAX;
                }
                if (g > 0){
                    // 当g大于零时，才可以向右或向下移动，所以，只需要在规定的范围内寻找最小的一个数即可
                    // 寻找最小的数可以用lower_bound函数
                    // lower_bound原来是用于寻找第一个大于n的数的, 此时只需要按照需求自定义一个函数就可以让它实现需要的功能
                    // 第一个是在列里面寻找,只要找到最小的移动步数,又因为当前格子到寻找的格子只需要一步
                    // 所以每次寻找到,就加1并求最小即可
                    auto it = lower_bound(col_st.begin(), col_st.end(), i+g, [](const auto &a, const int b){
                        return a.second > b;
                    });
                    if (it < col_st.end()){
                        mn = it->first+1;
                    }
                    // 在行里面寻找
                    it = lower_bound(row_st.begin(), row_st.end(), j+g, [](const auto &a, const int b){
                        return a.second > b;
                    });
                    if (it < row_st.end()){
                        mn = min(mn, it->first+1);
                    }
                }

                if (mn < INT_MAX){
                    // 当寻找到以后,为了维护列与行的单调性(这是为了用lower_bound二分查找),需要将小于mn的全部弹出
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
        // 最终如果找到了那么返回mn,否则返回-1
        return mn<INT_MAX ? mn : -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
    cout << s.minimumVisitedCells(grid) << endl;
}
