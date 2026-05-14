#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) cnt[i]++;
        int n = nums.size()-1;
        for (int i=1; i<n; i++){
            if (cnt[i] != 1){
                return false;
            }
        }
        if (cnt[n] != 2){
            return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,3,2};
    cout << s.isGood(nums) << endl;
}
