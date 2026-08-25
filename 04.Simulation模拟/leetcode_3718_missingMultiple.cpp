#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i=k;
        while (st.count(i)){
            i += k;
        }
        return i;
    }
};

int main(){
    Solution s;
    vector<int> nums = {8,2,3,4,6};
    int k = 2;
    cout << s.missingMultiple(nums, k) << endl;
}
