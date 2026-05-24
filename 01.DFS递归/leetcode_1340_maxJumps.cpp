#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int n, D;
    vector<int> Arr;
    unordered_map<int, int> memo;
    int dfs(int indx){
        if (memo.count(indx)){
            return memo[indx];
        }
        int ans = 1;
        for (int nxt=indx-1; nxt>=max(0, indx-D); nxt--){
            if (Arr[nxt] >= Arr[indx]){
                break;
            }
            ans = max(ans, 1+dfs(nxt));
        }
        for (int nxt=indx+1; nxt<=min(indx+D, n-1); nxt++){
            if (Arr[nxt] >= Arr[indx]){
                break;
            }
            ans = max(ans, 1+dfs(nxt));
        }
        memo[indx] = ans;
        return ans;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        Arr = arr;
        n = arr.size();
        D = d;
        int res = 0;
        for (int i=0; i<n; i++){
            res = max(res, dfs(i));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};
    int d = 2;
    cout << s.maxJumps(arr, d) << endl;
}
