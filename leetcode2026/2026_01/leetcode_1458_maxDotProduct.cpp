#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
private:
    vector<int> N1, N2;
    int n, m;
    unordered_map<int, int> memo;
    int dfs(int i, int j){
        if (i==n || j==m){
            return INT_MIN;
        }
        int key = i<<10 | j;
        if (memo.count(key)){
            return memo[key];
        }
        int res = max(dfs(i+1, j+1), 0)+N1[i]*N2[j];
        int res1 = dfs(i+1, j);
        int res2 = dfs(i, j+1);
        memo[key] = max(res, max(res1, res2));
        return memo[key];
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        N1 = nums1;
        N2 = nums2;
        return dfs(0, 0);
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2,1,-2,5}, nums2 = {3,0,-6};
    cout << s.maxDotProduct(nums1, nums2) << endl;
}
