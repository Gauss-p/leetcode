#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> neg, pos;
        for (int i : nums){
            if (i < 0){
                neg.push_back(i);
            }
            else if (i > 0){
                pos.push_back(i);
            }
            else{
                neg.push_back(i);
                pos.push_back(i);
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        int res1 = INT_MIN, res2 = INT_MIN, res3 = INT_MIN;
        if (pos.size() >= 3){
            res1 = pos[pos.size()-1]*pos[pos.size()-2]*pos[pos.size()-3];
        }
        if (pos.size() >= 1 && neg.size() >= 2){
            res2 = pos[pos.size()-1]*neg[0]*neg[1];
        }
        if (neg.size() >= 3){
            res3 = neg[neg.size()-1]*neg[neg.size()-2]*neg[neg.size()-3];
        }
        return max(res1, max(res2, res3));
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.maximumProduct(nums) << endl;
}
