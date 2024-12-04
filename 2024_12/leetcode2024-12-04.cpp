#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int>> calculate_moves(vector<vector<int>> direct, vector<int> pos){
        // 记录当前点的所有有效移动位置，用moves保存，其中存放的是五元组。五元组中，第一个和第二个元素表示当前点的初始坐标x和y，第三个和第四个元素表示当前点的移动方向dx和dy，第五个元素表示点(x,y)朝方向(dx,dy)移动了多少次，用step表示
        // 每一个点可以移动的方向已经在主函数中初始化完成了，在这个函数中，只需要遍历所有的方向(dx,dy)，并且从起始点pos(x,y)出发，每次将x和y分别加上dx和dy，获得一个新的点，并将step加1，同时把所有在边界以内的点按照五元组的格式加入moves列表中即可
        int x = pos[0], y = pos[1];
        vector<vector<int>> moves = {{x, y, 0, 0, 0}};
        for (auto d : direct){
            int dx = d[0], dy = d[1];
            // 新的坐标
            int nx = x+dx;
            int ny = y+dy;
            int step = 1; // 因为从nx,ny开始就已经是走了1步了，所以step应该从1开始计数
            while ((nx >= 1 and nx <= 8) && (ny >= 1 and ny <= 8)){
                moves.push_back({x, y, dx, dy, step}); // 将区域内的点加入列表
                // 更新下一个点
                nx += dx;
                ny += dy;
                step++;
            }
        }
        return moves;
    }

    bool is_valid(vector<int> m1, vector<int> m2){
        // m1和m2分别表示两个点的移动方式，同样都是五元组，当前函数用来判断m1和m2是否会在移动过程中重合，我们可以按照m1和m2中所记录的移动方式，从(x1,y1)和(x2,y2)同时出发，每次递增(dx1,dy1)和(dx2,dy2)，如果发现(x1,y1)和(x2,y2)已经重合，说明这两种移动方式已经无效
        int x1 = m1[0], y1 = m1[1], dx1 = m1[2], dy1 = m1[3], step1 = m1[4];
        int x2 = m2[0], y2 = m2[1], dx2 = m2[2], dy2 = m2[3], step2 = m2[4];
        for (int i=0; i<max(step1, step2); i++){
            // 依次递增
            if (i < step1){
                x1 += dx1;
                y1 += dy1;
            }
            if (i < step2){
                x2 += dx2;
                y2 += dy2;
            }
            if (x1==x2 && y1==y2){
                // 如果重合，返回false，表示这两种移动方式会重合
                return false;
            }
        }
        return true;
    }

public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        vector<vector<int>> rook_dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> bishop_dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<int>> queen_dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        unordered_map<string, vector<vector<int>>> all_dirs = {{"rook",rook_dir}, {"bishop",bishop_dir}, {"queen",queen_dir}};
        // 以上所有操作用来初始化三种棋子的所有移动方向
        int n = pieces.size();
        vector<vector<vector<int>>> all_moves;
        for (int i=0; i<n; i++){
            // 计算出每一个点的所有可能移动
            all_moves.push_back(calculate_moves(all_dirs[pieces[i]], positions[i]));
        }
        int res = 0;
        vector<vector<int>> paths(n); // 在下面的dfs中记录每一个点的移动方式，以便判断是否会出现重合
        auto dfs = [&](auto&& dfs, int i){
            if (i == n){
                // 如果i=n，那么说明棋子0到棋子n-1都已经选好移动方式，并且保证不会出现重合的情况，那么答案加1
                res++;
                return;
            }
            for (auto m2 : all_moves[i]){
                // 用m2循环棋子i所有可能的移动方式，只要发现和之前的所有确定下来的移动方式都不会重合，那么就继续判断下一个棋子该怎么走
                bool flag = true;
                for (int j=0; j<i; j++){
                    if (!is_valid(paths[j], m2)){
                        flag = false;
                    }
                }
                if (flag){
                    paths[i] = m2;
                    dfs(dfs, i+1);
                }
            }
        };
        dfs(dfs, 0); // 从第0个棋子开始选择位置
        return res;
    }
};

int main(){
    Solution s;
    vector<string> pieces = {"rook", "rook"};
    vector<vector<int>> positions = {{1,1}, {8,8}};
    cout << s.countCombinations(pieces, positions) << endl;
}
