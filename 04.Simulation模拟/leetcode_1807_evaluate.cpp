#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge){
            mp[k[0]] = k[1];
        }

        string res = "";
        string cur = "";
        for (char c : s){
            if (c == ')'){
                res += (mp.count(cur.substr(1)) ? mp[cur.substr(1)] : "?");
                cur = "";
            }
            else if (c == '(' || cur.size() > 0){
                cur += c;
            }
            else{
                res += c;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
    cout << sl.evaluate(s, knowledge) << endl;
}
