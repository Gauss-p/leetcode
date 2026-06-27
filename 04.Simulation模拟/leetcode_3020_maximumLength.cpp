#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int i : nums){
            cnt[i]++;
        }
        int res = cnt[1]-(1-cnt[1]%2);
        for (int i : nums){
            long long beg = i;
            if (beg == 1){
                continue;
            }
            int cur = 0;
            while (cnt[beg] >= 2){
                beg *= beg;
                cur += 2;
            }
            if (cnt[beg] >= 1){
                cur++;
            }
            else{
                cur--;
            }
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,4,1,2,2};
    cout << s.maximumLength(nums) << endl;
}
