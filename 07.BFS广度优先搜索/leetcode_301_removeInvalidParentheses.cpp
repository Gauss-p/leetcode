#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    unordered_map<char, int> val;
    bool check(string cur){
        int cnt = 0;
        for (auto& i : cur){
            cnt += val[i];
            if (cnt < 0){
                return false;
            }
        }
        return cnt==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        val = {{'(',1}, {')',-1}};
        vector<string> q = {s};
        while (!q.empty()){
            vector<string> res;
            unordered_set<string> nq;
            for (auto& i : q){
                if (check(i)){
                    res.push_back(i);
                }
                if (res.size()){
                    continue;
                }

                for (int indx=0; indx<i.size(); indx++){
                    nq.insert(i.substr(0, indx)+i.substr(indx+1));
                }
            }
            if (res.size()){
                return res;
            }
            q = vector<string>(nq.begin(), nq.end());
        }
        return {};
    }
};

int main(){
    Solution sl;
    string s = "()())()";
    vector<string> res = sl.removeInvalidParentheses(s);
    for (auto& i : res){
        cout << i << endl;
    }
}
