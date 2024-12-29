#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();
        vector<vector<int>> dic(26, vector<int>(m, 0));
        for (auto& v : votes){
            for (int i=0; i<m; i++){
                dic[v[i]-'A'][i]--;
            }
        }
        string res = votes[0];
        sort(res.begin(), res.end(), [&](char& a, char& b){
            for (int i=0; i<m; i++){
                if (dic[a-'A'][i] != dic[b-'A'][i]){
                    return dic[a-'A'][i] < dic[b-'A'][i];
                }
            }
            return a<b;
        });
        return res;
    }
};

int main(){
    Solution s;
    vector<string> votes = {"ABC","ACB","ABC","ACB","ACB"};
    cout << s.rankTeams(votes) << endl;
}
