#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subArray(n, 0);
        subArray[0] = nums[0];
        for (int i=1; i<n; i++){
            subArray[i] = nums[i]-nums[i-1];
        }
        int cnt = 0;
        vector<int> res(n-k+1, -1);
        for (int i=0; i<n; i++){
            if (subArray[i] == 1) cnt++;
            if (i < k-1) continue;
            if (subArray[i-k+1] == 1){
                cnt--;
            }
            if (cnt == k-1){
                res[i-k+1] = nums[i];
            }
            // if (subArray[i-k+1] == 1){
            //     cnt--;
            // }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;
    vector<int> res = s.resultsArray(nums, k);
    for (int &i : res) cout << i << " ";
    cout << endl;
}
