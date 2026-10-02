#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> dfs(int n, int cnt){
        if (n == 0){
            return {string(cnt, ')')};
        }
        vector<string> res;
        vector<string> nxt = dfs(n-1, cnt+1);
        for (auto& i : nxt){
            res.push_back("("+i);
        }
        if (cnt > 0){
            nxt = dfs(n, cnt-1);
            for (auto& i : nxt){
                res.push_back(")"+i);
            }
        }
        return res;
    }
public:
    vector<string> generateParenthesis(int n) {
        return dfs(n, 0);
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<string> res = s.generateParenthesis(n);
    for (auto& i : res){
        cout << i << endl;
    }
}
