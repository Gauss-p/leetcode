#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string str;
    int n;
    vector<vector<string>> res;
    vector<string> path;

    bool check(string tmp){
        for (int i=0; i<tmp.size()/2; i++){
            if (tmp[i] != tmp[tmp.size()-i-1]){
                return false;
            }
        }
        return true;
    }

    void dfs(int lastIndx){
        if (lastIndx == n-1){
            res.push_back(path);
            return;
        }
        for (int i=lastIndx+1; i<n; i++){
            string tmp = str.substr(lastIndx+1, i-lastIndx);
            if (check(tmp)){
                path.push_back(tmp);
                dfs(i);
                path.erase(path.end()-1);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        str = s;
        n = s.size();
        dfs(-1);
        return res;
    }
};

int main(){
    Solution sl;
    string s = "aab";
    vector<vector<string>> res = sl.partition(s);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
