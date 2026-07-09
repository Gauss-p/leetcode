#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<int> tmp;
    vector<int> N;
    vector<vector<int>> res;
    void dfs(int i){
        if (i == n){
            res.push_back(tmp);
            return;
        }

        int x = N[i];
        tmp.push_back(x);
        dfs(i+1);
        tmp.pop_back();

        i++;
        while (i<n && N[i] == x){
            i++;
        }
        dfs(i);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        N = nums;
        dfs(0);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,4,4,1,4};
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for (auto& i : res){
        for (auto& j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
