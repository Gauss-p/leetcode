#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i=0; i<n; i++){
            res[i] = nums[(((i+nums[i])%n)+n)%n];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,-2,1,1};
    vector<int> res = s.constructTransformedArray(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
