#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> res;
    int totalN;
    void dfs(int last, string s){
        if (s.size() == totalN){
            res.push_back(s);
            return;
        }
        if (last == 0){
            dfs(1, s+'1');
        }
        if (last == 1){
            dfs(0, s+'0');
            dfs(1, s+'1');
        }
    }
public:
    vector<string> validStrings(int n) {
        totalN = n;
        dfs(0, "0");
        dfs(1, "1");
        return res;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<string> res = s.validStrings(n);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
