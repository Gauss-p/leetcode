#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i=1; i<n; i++){
            diff[i] = nums[i]-nums[i-1];
            if (diff[i] == 0){
                return false;
            }
        }
        if (diff[1] < 0 || diff.back() < 0){
            return false;
        }
        vector<int> simp = {1};
        for (int i=1; i<n; i++){
            int x = diff[i];
            if (simp.back()*x < 0){
                simp.push_back(-simp.back());
            }
        }
        return simp.size()==3;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,4,2,6};
    cout << s.isTrionic(nums) << endl;
}
