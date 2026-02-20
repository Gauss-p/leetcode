#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int r = 0;
        vector<int> res;
        for (int i=0; i<n; i++){
            if (nums[i] == key){
                int l = max(r, i-k);
                r = min(n-1, i+k)+1;
                for (int j=l; j<r; j++){
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,4,9,1,3,9,5};
    int key = 9, k = 1;
    vector<int> res = s.findKDistantIndices(nums, key, k);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
