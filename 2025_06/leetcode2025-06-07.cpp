#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> pos(26);
        unordered_map<int, int> removed;
        for (int i=0; i<n; i++){
            if (s[i] != '*'){
                pos[s[i]-'a'].push_back(i);
            }
            else{
                for (int j=0; j<26; j++){
                    if (pos[j].size() > 0){
                        removed[pos[j][pos[j].size()-1]] = 1;
                        pos[j].erase(pos[j].end()-1);
                        break;
                    }
                }
            }
        }

        string res;
        for (int i=0; i<n; i++){
            if (s[i]=='*' || removed[i]){
                continue;
            }
            res += s[i];
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "aaba*";
    cout << sl.clearStars(s) << endl;
}
