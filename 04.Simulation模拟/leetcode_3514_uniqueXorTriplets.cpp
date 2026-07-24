#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int, int> mp0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                mp0[nums[i]^nums[j]] = 1;
            }
        }
        unordered_set<int> st;
        for (auto& kv : mp0){
            for (int i : nums){
                st.insert(kv.first ^ i);
            }
        }
        return st.size();
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3};
    cout << s.uniqueXorTriplets(nums) << endl;
}
