#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i=0; i<2*n; i++){
            while (v.size() && nums[v.back()] < nums[i%n]){
                res[v.back()] = nums[i%n];
                v.pop_back();
            }
            v.push_back(i%n);
        }
        // while (v.size()){
        //     res[v.back()] = -1;
        //     v.pop_back();
        // }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,3};
    vector<int> res = s.nextGreaterElements(nums);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
