#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_map<int, int> ban;
        for (int& i : banned){
            ban[i] = 1;
        }
        vector<vector<int>> pos_even_odd(2, vector<int>());
        for (int i=0; i<n; i++){
            if (ban[i] != 1 && i != p){
                pos_even_odd[i%2].push_back(i);
            }
        }
        pos_even_odd[0].push_back(n);
        pos_even_odd[1].push_back(n);

        vector<int> res(n, -1);
        res[p] = 0;
        queue<int> q;
        q.push(p);
        while (!q.empty()){
            int i = q.front();
            q.pop();
            int mn = max(i-k+1, k-i-1);
            int mx = min(i+k-1, 2*n-k-i-1);
            auto& pos = pos_even_odd[mn%2];
            int indx = lower_bound(pos.begin(), pos.end(), mn)-pos.begin();
            while (pos[indx]<=mx){
                int j = pos[indx];
                pos.erase(pos.begin()+indx);
                res[j] = res[i]+1;
                q.push(j);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n=4, p=0, k=4;
    vector<int> banned = {1,2};
    vector<int> res = s.minReverseOperations(n,p,banned,k);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
