#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int n, P;
    vector<int> NUMS;
    bool check(int mx){
        int i = 0, cnt = 0;
        while (i<n-1){
            if (abs(NUMS[i]-NUMS[i+1]) <= mx){
                cnt++;
                i += 2;
            }
            else{
                i += 1;
            }
        }
        return cnt >= P;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        NUMS = nums;
        n = nums.size();
        P = p;

        int l = 0, r = *max_element(nums.begin(), nums.end())-*min_element(nums.begin(), nums.end());
        while (l<r){
            int mid = (l+r)/2;
            if (check(mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,1,2,7,1,3};
    int p = 2;
    cout << s.minimizeMax(nums, p) << endl;
}
