#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> lang(languages.size());
        for (int i=0; i<languages.size(); i++){
            lang[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        vector<vector<int>> teach;
        for (auto& f : friendships){
            bool flag = true;
            int a = f[0]-1, b = f[1]-1;
            for (int l : languages[a]){
                if (lang[b].count(l)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                teach.push_back({a, b});
            }
        }

        int res = INT_MAX;
        for (int k=1; k<=n; k++){
            unordered_set<int> tmp;
            for (auto& t : teach){
                int a = t[0], b = t[1];
                if (lang[a].count(k)==0){
                    tmp.insert(a);
                }
                if (lang[b].count(k)==0){
                    tmp.insert(b);
                }
            }
            res = min(res, (int)tmp.size());
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 2;
    vector<vector<int>> languages = {{1},{2},{1,2}};
    vector<vector<int>> friendships = {{1,2},{1,3},{2,3}};
    cout << s.minimumTeachings(n, languages, friendships) << endl;
}
