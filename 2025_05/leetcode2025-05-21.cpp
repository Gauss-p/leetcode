#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> Nums;
    vector<vector<int>> Q;

    bool check(int m){
        int n = Nums.size();
        vector<int> newNums(n+1, 0);
        for (int i=0; i<m; i++){
            vector<int> q = Q[i];
            int l = q[0], r = q[1], v = q[2];
            newNums[l] += v;
            newNums[r+1] -= v;
        }
        int tmp = 0;
        for (int i=0; i<n; i++){
            tmp += newNums[i];
            if (tmp < Nums[i]){
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        Nums = nums;
        Q = queries;
        int l = 0, r = queries.size();
        if (!check(r)){
            return -1;
        }
        while (l<r){
            int mid = (l+r)/2;
            if (check(mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2,1},{0,2,1},{1,1,3}};
    cout << s.minZeroArray(nums, queries) << endl;
}
