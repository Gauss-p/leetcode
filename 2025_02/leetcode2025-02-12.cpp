#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l<r){
            int mid = (l+r)/2;
            if (mid==0){
                return 1;
            }
            int tmp = 0;
            for (int& i : nums){
                tmp += (i+mid-1)/mid-1;
            }
            if (tmp > maxOperations){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums = {9};
    int maxOperations = 2;
    cout << s.minimumSize(nums, maxOperations) << endl;
}
