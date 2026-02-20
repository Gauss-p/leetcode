#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

struct Node{
    Node* son[26]{};
    int sId = -1;
};

class Solution {
private:
    Node* root;
    int curSId;
    int n;
    string Source, Target;
    vector<vector<int>> dist;
    unordered_map<int, long long> memo;

    int plugIn(string s){
        Node* tmp = root;
        for (char i : s){
            if (!tmp->son[i-'a']){
                tmp->son[i-'a'] = new Node();
            }
            tmp = tmp->son[i-'a'];
        }

        if (tmp->sId == -1){
            tmp->sId = curSId;
            curSId++;
        }
        return tmp->sId;
    }

    long long dfs(int indx){
        if (indx == n){
            return 0;
        }
        if (memo.count(indx)){
            return memo[indx];
        }
        long long res = LLONG_MAX/2;
        if (Source[indx] == Target[indx]){
            res = min(res, dfs(indx+1));
        }
        Node* p = root;
        Node* q = root;
        for (int j=indx; j<n; j++){
            p = p->son[Source[j]-'a'];
            q = q->son[Target[j]-'a'];
            if ((!p) || (!q)){
                break;
            }
            if (p->sId == -1 || q->sId == -1){
                continue;
            }
            if (dist[p->sId][q->sId] < INT_MAX/2){
                res = min(res, dist[p->sId][q->sId]+dfs(j+1));
            }
        }
        memo[indx] = res;
        return res;
    }
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        root = new Node();
        curSId = 0;

        int m = original.size();
        dist.resize(2*m, vector<int>(2*m, INT_MAX/2));
        for (int i=0; i<m; i++){
            string x = original[i], y = changed[i];
            int c = cost[i];
            int xId = plugIn(x), yId = plugIn(y);
            dist[xId][yId] = min(dist[xId][yId], c);
        }

        for (int k=0; k<curSId; k++){
            for (int i=0; i<curSId; i++){
                if (dist[i][k] == INT_MAX){
                    continue;
                }
                for (int j=0; j<curSId; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        n = source.size();
        Source = source;
        Target = target;
        long long ans = dfs(0);
        return ans==LLONG_MAX/2 ? -1 : ans;
    }
};

int main(){
    Solution s;
    string source = "abcd", target = "acbe";
    vector<string> original = {"a","b","c","c","e","d"}, changed = {"b","c","b","e","b","e"};
    vector<int> cost = {2,5,5,1,2,20};
    cout << s.minimumCost(source, target, original, changed, cost) << endl;
}
