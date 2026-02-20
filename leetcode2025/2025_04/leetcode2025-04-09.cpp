#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        nums = vector<int>(st.begin(), st.end());
        int res = 0;
        for (int& i : nums){
            if (i<k){
                return -1;
            }
            res += (i>k);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,2,5,4,5};
    int k = 2;
    cout << s.minOperations(nums, k) << endl;
}
