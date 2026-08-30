#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int p1 = 0, p2 = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == mx){
                p1 = i;
            }
            if (nums[i] == mn){
                p2 = i;
            }
        }
        if (p1 > p2){
            swap(p1, p2);
        }
        return n-max(p1, max(n-p2-1, p2-p1-1));
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,10,7,5,4,1,8,6};
    cout << s.minimumDeletions(nums) << endl;
}
