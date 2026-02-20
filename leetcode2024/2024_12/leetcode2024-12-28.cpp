#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> dic;
        for (int i : nums){
            dic[i]++;
            if (dic[i] >= 3){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,3,4};
    cout << s.isPossibleToSplit(nums) << endl;
}
