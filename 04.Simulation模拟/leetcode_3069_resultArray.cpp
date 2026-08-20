#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int pos = 0;
        vector<int> res = {nums[0], nums[1]};
        for (int i=2; i<nums.size(); i++){
            int x = nums[i];
            if (res[pos] > res.back()){
                pos++;
                res.insert(res.begin()+pos, x);
            }
            else{
                res.push_back(x);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3};
    vector<int> res = s.resultArray(nums);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
