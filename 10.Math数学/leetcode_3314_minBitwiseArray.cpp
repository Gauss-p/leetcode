#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int& i : nums){
            int cur = ((i^(i+1))+1)>>2;
            if (cur == 0){
                res.push_back(-1);
            }
            else{
                res.push_back(i-cur);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,5,7};
    vector<int> res = s.minBitwiseArray(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
