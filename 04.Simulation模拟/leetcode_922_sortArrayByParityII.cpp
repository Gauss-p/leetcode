#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int odd = 1, even = 0;
        for (int& i : nums){
            if (i&1){
                res[odd] = i;
                odd += 2;
            }
            else{
                res[even] = i;
                even += 2;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,5,7};
    vector<int> res = s.sortArrayByParityII(nums);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
