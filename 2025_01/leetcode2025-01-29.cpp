#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; i++){
            mp[nums[i]]++;
            if (mp[nums[i]] >= 2){
                return true;
            }
            if (i<k){
                continue;
            }
            mp[nums[i-k]]--;
        }
        return false;
    }
};

int main(){
	Solution s;
	vector<int> nums = {1,2,3,1};
	int k = 3;
	cout << s.containsNearbyDuplicate(nums, k) << endl;
}
