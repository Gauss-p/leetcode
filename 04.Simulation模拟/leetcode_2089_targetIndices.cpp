#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt1=0, cnt2=0;
        for (int& i : nums){
            if (i<target) cnt1++;
            else if (i==target) cnt2++;
        }
        vector<int> res;
        while (cnt2){
            res.push_back(cnt1++);
            cnt2--;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,5,2,3};
    int target = 2;
    vector<int> res = s.targetIndices(nums, target);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
