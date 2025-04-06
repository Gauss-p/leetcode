#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> from_, N;
    unordered_map<int, int> memo;
    int dfs(int i){
        if (memo.count(i)){
            return memo[i];
        }
        int res = 0;
        for (int j=0; j<i; j++){
            if (N[i]%N[j]){
                continue;
            }
            int tmpLength = dfs(j);
            if (tmpLength > res){
                res = tmpLength;
                from_[i] = j;
            }
        }
        memo[i] = res+1;
        return res+1;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        N = nums;
        int n = nums.size();
        from_.resize(n, -1);

        int maxLength = 0;
        int end;
        for (int i=0; i<n; i++){
            memo.clear();
            int tmp = dfs(i);
            if (tmp > maxLength){
                maxLength = tmp;
                end = i;
            }
        }

        vector<int> ans;
        while (end != -1){
            ans.push_back(nums[end]);
            end = from_[end];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<int> res = s.largestDivisibleSubset(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
