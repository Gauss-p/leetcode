#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        for (int i=0; i<n; i++){
            pos[nums[i]].push_back(i);
        }
        int res = INT_MAX;
        for (auto& kv : pos){
            vector<int> v = kv.second;
            if (v.size() < 3){
                continue;
            }
            for (int i=0; i<v.size()-2; i++){
                res = min(res, v[i+2]-v[i]);
            }
        }
        return res==INT_MAX ? -1 : res*2;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,1,3};
    cout << s.minimumDistance(nums) << endl;
}
