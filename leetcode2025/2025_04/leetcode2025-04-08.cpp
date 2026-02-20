#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i=n-1; i>=0; i--){
            // if (st.count(nums[i])){
            //     return (i+3)/3;
            // }
            // st.insert(nums[i]);
            // 上下两段的效果相同，但是下面的判断中用到了unordered_set中insert函数的返回值，它的返回值的第一项是一个迭代器，如果插入成功，那么迭代器指向插入的元素，第二项是一个布尔值，如果插入成功，该值为true，否则为false。同时，只有当元素本不存在于set中时才能插入成功
            if (!st.insert(nums[i]).second){
                return (i+3)/3;
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,2,3,3,5,7};
    cout << s.minimumOperations(nums) << endl;
}
