#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int n = nums.size();
        while (k--){
            int tmp = pq.top();
            pq.pop();
            int indx = find(nums.begin(), nums.end(), tmp)-nums.begin();
            // int indx = 0;
            // for (; indx<n; indx++){
            //     if (nums[indx] == tmp){
            //         break;
            //     }
            // }
            tmp *= multiplier;
            pq.push(tmp);
            nums[indx] = tmp;
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;
    vector<int> res = s.getFinalState(nums, k, multiplier);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
