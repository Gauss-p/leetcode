#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i=0; i<n; i++){
            unordered_set<int> st;
            for (int j=i; j<n; j++){
                st.insert(nums[j]);
                res += st.size()*st.size();
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> res = {1,2,1};
    cout << s.sumCounts(res) << endl;
}
