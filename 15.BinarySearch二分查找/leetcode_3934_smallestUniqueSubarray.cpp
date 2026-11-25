#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> Nums;
    bool check(int mid){
        long long b1 = 100007, m1 = 1e9+7;
        long long p1 = 1, w1 = 0;
        for (int i=0; i<mid; i++){
            w1 = (w1*b1+Nums[i])%m1;
            p1 = (p1*b1)%m1;
        }

        unordered_map<long long, int> cnt;
        cnt[w1] = 1;
        for (int i=mid; i<Nums.size(); i++){
            w1 = (w1*b1+Nums[i]-p1*Nums[i-mid])%m1;
            w1 = (w1+m1)%m1;
            cnt[w1] += 1;
        }

        for (auto& kv : cnt){
            if (kv.second == 1){
                return true;
            }
        }
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        Nums = nums;
        int l = 1, r = n;
        while (l<=r){
            int mid = (l+r)>>1;
            if (check(mid)){
                r = mid-1;
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
    vector<int> nums = {3,3,3};
    cout << s.smallestUniqueSubarray(nums) << endl;
}
