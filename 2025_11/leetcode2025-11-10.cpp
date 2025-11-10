#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        int res = 0;
        for (auto& i : nums){
            while (!st.empty() && st.back() > i){
                res++;
                st.pop_back();
            }
            if (st.empty() || i != st.back()){
                st.push_back(i);
            }
        }
        return res+st.size()-(st[0]==0);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,2,1};
    cout << s.minOperations(nums) << endl;
}
