#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i : nums){
            if (mp[i]){
                res.push_back(i);
            }
            else{
                mp[i]++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,1,0};
    vector<int> res = s.getSneakyNumbers(nums);
    cout << res[0] << " " << res[1] << endl;
}
