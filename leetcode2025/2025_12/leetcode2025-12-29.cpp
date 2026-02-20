#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> group;
    unordered_map<string, bool> memo;
    
    bool dfs(const string& line){
        if (line.size() == 1){
            return true;
        }
        if (memo.count(line)){
            return memo[line];
        }
        bool ans = false;
        unordered_set<string> mode;
        for (int i=0; i<line.size()-1; i++){
            string cur = line.substr(i, 2);
            if (!group.count(cur)){
                return false;
            }
            if (mode.size() == 0){
                mode = unordered_set<string>(group[cur].begin(), group[cur].end());
                continue;
            }
            unordered_set<string> newMode;
            for (auto& c : group[cur]){
                for (auto& x : mode){
                    newMode.insert(x+c);
                }
            }
            mode = move(newMode);
        }

        for (auto& m : mode){
            if (dfs(m)){
                return memo[line]=true;
            }
        }
        return memo[line]=false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& a : allowed){
            group[a.substr(0, 2)].push_back(a.substr(2, 1));
        }
        return dfs(bottom);
    }
};

int main(){
    Solution s;
    string bottom = "BCD";
    vector<string> allowed = {"BCC","CDE","CEA","FFF"};
    cout << s.pyramidTransition(bottom, allowed) << endl;
}
