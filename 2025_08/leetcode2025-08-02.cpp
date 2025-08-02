#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int, int> cnt;
        int mnCost = INT_MAX;
        for (int i=0; i<n; i++){
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
            mnCost = min(mnCost, min(basket1[i], basket2[i]));
        }
        vector<int> tot;
        for (auto&kv : cnt){
            if (abs(kv.second) & 1){
                return -1;
            }
            for (int i=0; i<abs(kv.second)/2; i++){
                tot.push_back(kv.first);
            }
        }
        if (tot.size() == 0){
            return 0;
        }

        sort(tot.begin(), tot.end());
        mnCost *= 2;
        long long res = 0;
        for (int i=0; i<tot.size()/2; i++){
            res += min(tot[i], mnCost);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> basket1 = {4,2,2,2};
    vector<int> basket2 = {1,4,1,2};
    cout << s.minCost(basket1, basket2) << endl;
}
