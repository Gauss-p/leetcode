#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> new_nums;
        new_nums.push_back(1);
        int n = nums.size();
        for (int i=1; i<n; i++){
            if ((nums[i]%2)+(nums[i-1]%2) != 1){
                new_nums.push_back(new_nums[i-1]+1);
            }
            else{
                new_nums.push_back(new_nums[i-1]);
            }
        }
        vector<bool> res(queries.size(), false);
        for (int i=0; i<queries.size(); i++){
            auto q = queries[i];
            if (new_nums[q[0]] == new_nums[q[1]]){
                res[i] = true;
            }
        }
        return res;
    }
    vector<bool> isArraySpecial1(vector<int>& nums, vector<vector<int>>& queries) {
        int indx = 0;
        int n = nums.size();
        vector<int> from, to;
        while (indx < n){
            int tmp = indx+1;
            for (;tmp < n; tmp++){
                if ((nums[tmp]%2)+(nums[tmp-1]%2) != 1){
                    break;
                }
            }
            from.push_back(indx);
            to.push_back(tmp-1);
            indx = tmp;
        }
        // for (int i=0; i<from.size(); i++){
        //     cout << from[i] << " " << to[i] << endl;
        // }
        vector<bool> res(queries.size(), false);
        for (int i=0; i<queries.size(); i++){
            int f = queries[i][0], t = queries[i][1];
            int indxF = lower_bound(from.begin(), from.end(), f)-from.begin();
            for (int j=indxF; j>=0 && from[j]<=f; j--){
                if (to[j] >= t){
                    res[i] = true;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,4}};
    vector<bool> res = s.isArraySpecial(nums, queries);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
