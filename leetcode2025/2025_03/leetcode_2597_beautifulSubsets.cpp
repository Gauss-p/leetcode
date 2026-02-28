#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    unordered_map<int, int> path;
    vector<int> Nums;
    int res;
    int K;
    
    void dfs(int lastIndx){
        res++;
        for (int i=lastIndx+1; i<n; i++){
            if (path[Nums[i]-K]==0){
                path[Nums[i]]++;
                dfs(i);
                path[Nums[i]]--;
            }
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        Nums = nums;
        res = -1;
        K = k;
        dfs(-1);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,4,6};
    int k = 2;
    cout << s.beautifulSubsets(nums,k) << endl;
}
