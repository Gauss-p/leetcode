#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int res = 0;
        unordered_map<string, int> mp = {{"UP",-n}, {"RIGHT",1}, {"LEFT",-1}, {"DOWN",n}};
        for (auto s : commands){
            res += mp[s];
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 2;
    vector<string> commands = {"RIGHT", "DOWN"};
    cout << s.finalPositionOfSnake(n, commands) << endl;
}
