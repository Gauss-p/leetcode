#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end()), mx = *max_element(nums.begin(), nums.end());
        vector<int> res;
        for (int i=mn; i<=mx; i++){
            if (st.count(i) == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,2,5};
    vector<int> res = s.findMissingElements(nums);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
