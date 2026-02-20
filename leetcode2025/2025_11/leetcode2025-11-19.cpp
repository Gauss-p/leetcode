#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st(nums.begin(), nums.end());
        while (st.count(original)){
            original *= 2;
        }
        return original;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,3,6,1,12};
    int original = 3;
    cout << s.findFinalValue(nums, original) << endl;
}
