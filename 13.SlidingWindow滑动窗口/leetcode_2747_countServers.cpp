#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto&a, auto&b){
            return a[1] < b[1];
        });
        vector<int> indxs;
        for (int i=0; i<queries.size(); i++){
            indxs.push_back(i);
        }
        sort(indxs.begin(), indxs.end(), [&queries](auto&a, auto&b){
            return queries[a] < queries[b];
        });
        int active = 0;
        vector<int> res(queries.size(), 0);
        int l = 0, r = 0;
        unordered_map<int, int> cnt;
        
        for (int i : indxs){
            int v = queries[i];
            while (r<logs.size() && logs[r][1]<=v){
                if (cnt[logs[r][0]] == 0){
                    active++;
                }
                cnt[logs[r][0]]++;
                r++;
            }

            while (l<logs.size() && logs[l][1]<v-x){
                cnt[logs[l][0]]--;
                if (cnt[logs[l][0]] == 0){
                    active--;
                }
                l++;
            }
            res[i] = n-active;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3, x = 5;
    vector<int> queries = {10,11};
    vector<vector<int>> logs = {{1,3},{2,6},{1,5}};
    vector<int> res = s.countServers(n, logs, x, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
