#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> cnt(10, vector<int>(9, 0));
        vector<int> s(9, 0);
        int n = nums.size();
        for (int i : nums){
            int col = 0;
            while (i > 0){
                cnt[i%10][col]++;
                s[col]++;
                i /= 10;
                col++;
            }
        }
        long long res = 0;
        for (int c=0; c<9; c++){
            int tmp = 0;
            for (auto r : cnt){
                tmp += r[c];
                res += 1ll*r[c]*(s[c]-tmp);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {13,23,12};
    Solution s;
    cout << s.sumDigitDifferences(nums) << endl;
}
