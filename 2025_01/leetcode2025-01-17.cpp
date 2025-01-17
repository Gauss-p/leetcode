#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    vector<int> orList;
    int myCalc(vector<int>& orList){
        int tmp = 0;
        for (int i=0; i<32; i++){
            if (orList[i] > 0){
                tmp += (1<<i);
            }
        }
        return tmp;
    }
    void update(int x, int op){
        for (int i=0; i<32; i++){
            if ((x>>i)&1){
                orList[i] += op;
            }
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        orList.resize(32, 0);
        int n = nums.size();
        int l = 0;
        int res = INT_MAX;
        for (int r=0; r<n; r++){
            update(nums[r], 1);
            while (l<=r && myCalc(orList)>=k){
                res = min(res, r-l+1);
                update(nums[l], -1);
                l++;
            }
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,8};
    int k = 10;
    cout << s.minimumSubarrayLength(nums, k) << endl;
}
