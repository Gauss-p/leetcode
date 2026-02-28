#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> g(n+1);
        for (auto& c : conflictingPairs){
            int a = c[0], b = c[1];
            if (a>b){
                swap(a, b);
            }
            g[a].push_back(b);
        }

        long long res = 0;
        vector<long long> extra(n+2, 0);
        vector<int> b(2, n+1);
        for (int i=n; i>0; i--){
            vector<int> tmp(g[i].size()+2);
            merge(b.begin(), b.end(), g[i].begin(), g[i].end(), tmp.begin());
            sort(tmp.begin(), tmp.end());
            b[0] = tmp[0];
            b[1] = tmp[1];
            res += (b[0]-i);
            extra[b[0]] += (b[1]-b[0]);
        }

        return res+*max_element(extra.begin(), extra.end());
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> conflictingPairs = {{2,3},{1,4}};
    cout << s.maxSubarrays(n, conflictingPairs) << endl;
}
