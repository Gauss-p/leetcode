#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    bool findMinPairsAndDelete(vector<int>& nums){
        int n = nums.size();
        bool flag = false;
        int minSum = INT_MAX;
        pair<int, int> ans;
        for (int i=1; i<n; i++){
            if (nums[i-1] > nums[i]){
                flag = true;
            }
            if (nums[i-1]+nums[i] < minSum){
                minSum = nums[i-1]+nums[i];
                ans = make_pair(i-1, i);
            }
        }
        if (flag){
            nums.erase(nums.begin()+ans.second);
            nums.erase(nums.begin()+ans.first);
            nums.insert(nums.begin()+ans.first, minSum);
        }
        return flag;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        while (true){
            bool flag = findMinPairsAndDelete(nums);
            if (flag){
                res++;
            }
            else{
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,2,3,1};
    cout << s.minimumPairRemoval(nums) << endl;
}
