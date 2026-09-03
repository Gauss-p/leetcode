#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEven = INT_MAX, minOdd = INT_MAX;
        for (int i : nums1){
            if (i&1){
                minOdd = min(minOdd, i);
            }
            else{
                minEven = min(minEven, i);
            }
        }
        if (minOdd == INT_MAX || minEven == INT_MAX){
            return true;
        }
        if (minOdd < minEven){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,7};
    cout << s.uniformArray(nums) << endl;
}
