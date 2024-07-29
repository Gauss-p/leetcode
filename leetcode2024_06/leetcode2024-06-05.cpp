#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]}, arr1_copy = {nums[0]};
        vector<int> arr2 = {nums[1]}, arr2_copy = {nums[1]};
        int n = nums.size();
        for (int i=2; i<n; i++){
            int tmp = nums[i];
            int l1 = arr1.size(), l2 = arr2.size();
            auto it1 = lower_bound(arr1_copy.begin(), arr1_copy.end(), tmp+1);
            auto it2 = lower_bound(arr2_copy.begin(), arr2_copy.end(), tmp+1);
            int big1 = arr1_copy.end()-it1, big2 = arr2_copy.end()-it2;
            if (big1 > big2 || (big1 == big2 && arr1.size() <= arr2.size())){
                arr1.push_back(tmp);
                arr1_copy.insert(it1, tmp);
                continue;
            }
            if (big1 < big2 || (big1 == big2 && arr1.size() > arr2.size())){
                arr2.push_back(tmp);
                arr2_copy.insert(it2, tmp);
                continue;
            }
        }
        vector<int> res;
        // cout << arr1.size() << " " << arr2.size();
        for (auto i : arr1) res.push_back(i);
        for (auto i : arr2) res.push_back(i);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3,3};
    vector<int> res =  s.resultArray(nums);
    for (auto i : res){
        cout << i << " ";
    }
}
