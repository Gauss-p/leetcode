#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int x : nums){
            string s = to_string(x);
            for (auto& c : s){
                res.push_back(c-'0');
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {12,25,83,7,7};
    vector<int> res = s.separateDigits(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
