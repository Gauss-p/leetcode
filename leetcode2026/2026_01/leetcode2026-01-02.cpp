#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& i : nums){
            if (cnt[i]==1){
                return i;
            }
            cnt[i]++;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,3};
    cout << s.repeatedNTimes(nums) << endl;
}
