#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        vector<int> stl;
        long long tot = 0;
        int res0 = nums[0];
        long long res1 = LLONG_MAX;

        for (int i=1; i<n; i++){
            auto it = lower_bound(stl.begin(), stl.end(), nums[i]);
            stl.insert(it, nums[i]);
            if (stl.size() <= k-1){
                tot += nums[i];
            }
            else{
                int indx = lower_bound(stl.begin(), stl.end(), nums[i])-stl.begin();
                if (indx < k-1){
                    tot -= stl[k-1];
                    tot += nums[i];
                }
            }

            if (i <= dist){
                continue;
            }

            res1 = min(res1, tot);
            int indx2 = lower_bound(stl.begin(), stl.end(), nums[i-dist])-stl.begin();
            if (indx2 < k-1){
                tot -= nums[i-dist];
                if (stl.size() > k-1){
                    tot += stl[k-1];
                }
            }
            stl.erase(stl.begin()+indx2);
        }
        return res0+res1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,6,4,2};
    int k = 3, dist = 3;
    cout << s.minimumCost(nums, k, dist) << endl;
}
