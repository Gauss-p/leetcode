#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int, int> mp;
        for (auto& item : items){
            mp[item[0]] = max(mp[item[0]], item[1]);
        }
        vector<pair<int, int>> tot;
        for (auto& kv : mp){
            tot.push_back(make_pair(kv.first, kv.second));
        }
        sort(tot.begin(), tot.end());
        for (int i=1; i<tot.size(); i++){
            tot[i].second = max(tot[i].second, tot[i-1].second);
        }

        int n = queries.size();
        vector<int> res(n, 0);
        for (int i=0; i<n; i++){
            int indx = lower_bound(tot.begin(), tot.end(), make_pair(queries[i], INT_MAX))-tot.begin();
            if (indx != 0){
                res[i] = tot[indx-1].second;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1,2,3,4,5,6};
    vector<int> res = s.maximumBeauty(items, queries);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
