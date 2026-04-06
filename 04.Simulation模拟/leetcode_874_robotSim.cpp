#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int curDir = 0;
        int x = 0, y = 0;
        unordered_map<int, unordered_set<int>> st;
        for (auto& i : obstacles){
            st[i[0]].insert(i[1]);
        }

        int res = 0;
        for (int op : commands){
            if (op == -1){
                curDir = (curDir+1)%4;
            }
            else if (op == -2){
                curDir = (curDir+3)%4;
            }
            else{
                int dx = dirs[curDir][0], dy = dirs[curDir][1];
                for (int i=0; i<op; i++){
                    if (st[x+dx].count(y+dy) == 0){
                        x += dx;
                        y += dy;
                    }
                }
                res = max(res, x*x+y*y);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> commands = {4,-1,3};
    vector<vector<int>> obstacles = {};
    cout << s.robotSim(commands, obstacles) << endl;
}
