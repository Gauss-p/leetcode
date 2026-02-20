#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    int clock;
    vector<int> Xor;
    vector<int> inTime;
    vector<int> outTime;
    vector<int> Nums;
    vector<vector<int>> g;

    void dfs(int x, int pa){
        clock++;
        inTime[x] = clock;
        Xor[x] = Nums[x];
        for (auto& y : g[x]){
            if (y != pa){
                dfs(y, x);
                Xor[x] ^= Xor[y];
            }
        }
        outTime[x] = clock;
    }

    bool is_pa(int x, int y){
        return ((inTime[x] < inTime[y]) && (outTime[y] <= outTime[x]));
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        g.resize(n);
        for (auto&e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        Xor.resize(n, 0);
        inTime.resize(n, 0);
        outTime.resize(n, 0);
        clock = 0;
        Nums = nums;
        dfs(0, -1);

        int res = INT_MAX;
        for (int x=1; x<n; x++){
            for (int y=x+1; y<n; y++){
                int a, b, c;
                if (is_pa(x, y)){
                    a = Xor[y];
                    b = Xor[x]^Xor[y];
                    c = Xor[0]^Xor[x];
                }
                else if (is_pa(y, x)){
                    a = Xor[x];
                    b = Xor[y]^Xor[x];
                    c = Xor[0]^Xor[y];
                }
                else{
                    a = Xor[x];
                    b = Xor[y];
                    c = Xor[0]^Xor[x]^Xor[y];
                }
                res = min(res, max(a, max(b, c))-min(a, min(b, c)));
                if (res == 0){
                    return 0;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,5,5,4,11};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    cout << s.minimumScore(nums, edges) << endl;
}
