#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for (int i=0; i<nums.size(); i++){
            res += ('0'+('1'-nums[i][i]));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> nums = {"01","10"};
    cout << s.findDifferentBinaryString(nums) << endl;
}
