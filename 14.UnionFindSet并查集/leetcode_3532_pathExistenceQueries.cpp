#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UFS{
private:
    vector<int> pa;
public:
    UFS(int n){
        for (int i=0; i<n; i++){
            pa.push_back(i);
        }
    }

    int find(int x){
        if (pa[x] != x){
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        if (px < py){
            pa[py] = px;
        }
        else{
            pa[px] = py;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UFS ufs(n);
        for (int i=0; i<n; i++){
            int last = lower_bound(nums.begin(), nums.end(), nums[i]-maxDiff)-nums.begin();
            ufs.merge(last, i);
        }

        vector<bool> res;
        for (auto& q : queries){
            res.push_back(ufs.find(q[0])==ufs.find(q[1]));
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 2;
    vector<int> nums = {1,3};
    int maxDiff = 1;
    vector<vector<int>> queries = {{0,0},{0,1}};
    vector<bool> res = s.pathExistenceQueries(n, nums, maxDiff, queries);
    for (bool i : res){
        cout << i << " ";
    }
    cout << endl;
}
