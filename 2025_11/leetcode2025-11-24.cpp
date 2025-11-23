#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int cur = 0;
        for (int& i : nums){
            cur = ((cur<<1)+i)%5;
            res.push_back(cur==0);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,1};
    vector<bool> res = s.prefixesDivBy5(nums);
    for (bool i : res){
        cout << i << " ";
    }
    cout << endl;
}
