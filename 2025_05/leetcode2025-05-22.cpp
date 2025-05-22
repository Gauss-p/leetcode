#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size();
        vector<int> sub(n+1, 0);
        int op = 0;
        int j = 0;
        priority_queue<int> q;
        for (int i=0; i<n; i++){
            int cur = nums[i];
            op += sub[i];
            while (j<queries.size() && queries[j][0] == i){
                q.push(queries[j][1]);
                j++;
            }
            while (op<nums[i] && !q.empty() && q.top() >= i){
                int tmp = q.top();
                q.pop();
                sub[tmp+1]--;
                op++;
            }
            if (op<nums[i]){
                return -1;
            }
        }
        return q.size();
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2},{0,2},{1,1}};
    cout << s.maxRemoval(nums, queries) << endl;
}
