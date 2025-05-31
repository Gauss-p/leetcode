#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int n;
    pair<int, int> get_pos(int x){
        x -= 1;
        int row = x/n, col = x%n;
        if (row&1){
            col = n-1-col;
        }
        row = n-1-row;
        return make_pair(row, col);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        vector<int> visited(n*n, 0);
        while (!q.empty()){
            auto tmp = q.front();
            q.pop();
            int cur = tmp.first, dis = tmp.second;
            if (visited[cur]){
                continue;
            }
            visited[cur] = 1;
            for (int tmp_nxt=cur+1; tmp_nxt<=min(n*n, cur+6); tmp_nxt++){
                auto pos = get_pos(tmp_nxt);
                int x = pos.first, y = pos.second;
                int nxt = tmp_nxt;
                if (board[x][y] != -1){
                    nxt = board[x][y];
                }
                if (nxt == n*n){
                    return dis+1;
                }
                q.push(make_pair(nxt, dis+1));
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    cout << s.snakesAndLadders(board) << endl;
    return 0;
}
