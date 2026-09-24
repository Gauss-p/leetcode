#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int mySum(int x){
        int ans = 0;
        while (x){
            ans += x%10;
            x /= 10;
        }
        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (i == mySum(nums[i])){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2};
    cout << s.smallestIndex(nums) << endl;
}
