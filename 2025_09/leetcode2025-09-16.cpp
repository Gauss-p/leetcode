#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        int n = nums.size(), i = 0;
        while (i<n){
            st.push_back(nums[i]);
            while (st.size()>1 && __gcd(st[st.size()-1], st[st.size()-2])>1){
                int a = st.back();
                st.erase(st.end()-1);
                int b = st.back();
                st.erase(st.end()-1);
                st.push_back(1ll*a*b/(__gcd(a, b)));
            }
            i++;
        }
        return st;
    }
};

int main(){
    Solution s;
    vector<int> nums = {6,4,3,2,7,6,2};
    vector<int> res = s.replaceNonCoprimes(nums);
    for (auto& i : res){
        cout << i << " ";
    }
    cout << endl;
}
