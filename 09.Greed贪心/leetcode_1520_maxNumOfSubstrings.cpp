#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> pos;
        for (int i=0; i<s.size(); i++){
            char c = s[i];
            if (pos.count(c)){
                pos[c].second = i;
            }
            else{
                pos[c] = make_pair(i, i);
            }
        }

        vector<pair<int, int>> spaces;
        for (auto& p : pos){
            char c = p.first;
            int l = pos[c].first, r = pos[c].second;
            int nl = l, nr = l;
            while (nl>=l || nr<=r){
                int indx = (nl>=l ? nl : nr);
                char nc = s[indx];
                if (pos[nc].first < l){
                    l = pos[nc].first;
                }
                if (pos[nc].second > r){
                    r = pos[nc].second;
                }
                if (indx == nl){
                    nl -= 1;
                }
                if (indx == nr){
                    nr += 1;
                }
            }
            spaces.emplace_back(l, r);
        }

        sort(spaces.begin(), spaces.end(), [](auto&a, auto&b){
            return a.second < b.second;
        });
        vector<string> res;
        int end = -1;
        for (auto& sp : spaces){
            if (end < sp.first){
                res.push_back(s.substr(sp.first, sp.second-sp.first+1));
                end = sp.second;
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "adefaddaccc";
    vector<string> res = sl.maxNumOfSubstrings(s);
    for (auto& s : res){
        cout << s << " ";
    }
    cout << endl;
}
