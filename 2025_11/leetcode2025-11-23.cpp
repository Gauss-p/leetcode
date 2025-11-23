#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int tot = 0;
        int one1=INT_MAX, one2=INT_MAX, two1=INT_MAX, two2=INT_MAX;
        for (int i : nums){
            tot += i;
            if (i%3 == 1){
                if (i<=one1){
                    one2 = one1;
                    one1 = i;
                }
                else if (i<one2){
                    one2 = i;
                }
            }
            if (i%3 == 2){
                if (i<=two1){
                    two2 = two1;
                    two1 = i;
                }
                else if (i<two2){
                    two2 = i;
                }
            }
        }

        if (tot%3 == 0){
            return tot;
        }
        if (tot%3 == 1){
            int res = 0;
            if (one1 != INT_MAX){
                res = max(res, tot-one1);
            }
            if (two2 != INT_MAX){
                res = max(res, tot-two1-two2);
            }
            return res;
        }
        int res = 0;
        if (two1 != INT_MAX){
            res = max(res, tot-two1);
        }
        if (one2 != INT_MAX){
            res = max(res, tot-one1-one2);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,6,5,1,8};
    cout << s.maxSumDivThree(nums) << endl;
}
