#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<vector<pair<int, int>>> g;
    vector<int> generateDist(int c){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(make_pair(0, c));
        vector<int> dist(26, INT_MAX);
        dist[c] = 0;
        vector<int> visited(26, 0);
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            int d = cur.first, x = cur.second;
            if (visited[x] == 1){
                continue;
            }
            visited[x] = 1;
            for (auto& nxt : g[x]){
                int y = nxt.first, cost = nxt.second;
                int cur = d+cost;
                if (cur < dist[y]){
                    dist[y] = cur;
                    q.push(make_pair(cur, y));
                }
            }
        }
        return dist;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size(), m = source.size();
        g.resize(26);
        for (int i=0; i<n; i++){
            g[original[i]-'a'].emplace_back(changed[i]-'a', cost[i]);
        }

        unordered_map<int, vector<int>> dic;
        long long res = 0;
        for (int i=0; i<m; i++){
            if (source[i] != target[i]){
                if (dic.count(source[i]-'a') == 0){
                    dic[source[i]-'a'] = generateDist(source[i]-'a');
                }
                if (dic[source[i]-'a'][target[i]-'a'] == INT_MAX){
                    return -1;
                }
                res += dic[source[i]-'a'][target[i]-'a'];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string source = "abcd", target = "acbe";
    vector<char> original = {'a','b','c','c','e','d'}, changed = {'b','c','b','e','b','e'};
    vector<int> cost = {2,5,5,1,2,20};
    cout << s.minimumCost(source, target, original, changed, cost) << endl;
}
