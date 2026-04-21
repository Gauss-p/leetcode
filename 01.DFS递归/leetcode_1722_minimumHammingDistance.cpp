#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> visited, Source, Target;
    vector<vector<int>> g;
    unordered_map<int, int> cnt;

    void dfs(int x){
        cnt[Source[x]]++;
        cnt[Target[x]]--;
        visited[x] = 1;
        for (int y : g[x]){
            if (visited[y]){
                continue;
            }
            dfs(y);
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        Source = source;
        Target = target;
        g.resize(n);
        visited.resize(n, 0);
        for (auto& aS : allowedSwaps){
            g[aS[0]].push_back(aS[1]);
            g[aS[1]].push_back(aS[0]);
        }

        int res = 0;
        for (int i=0; i<n; i++){
            if (visited[i] == 0){
                cnt.clear();
                dfs(i);
                for (auto& kv : cnt){
                    res += abs(kv.second);
                }
            }
        }
        return res/2;
    }
};

int main(){
    Solution s;
    vector<int> source = {1,2,3,4}, target = {2,1,4,5};
    vector<vector<int>> allowedSwaps = {{0,1},{2,3}};
    cout << s.minimumHammingDistance(source, target, allowedSwaps) << endl;
}
