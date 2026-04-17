#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int reverseNum(int x){
        string s = to_string(x);
        int y = 0;
        for (int i=s.size()-1; i>=0; i--){
            y = y*10+(s[i]-'0');
        }
        return y;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        unordered_map<int, int> pos;
        for (int i=0; i<n; i++){
            if (pos.count(nums[i])){
                res = min(res, i-pos[nums[i]]);
            }
            pos[reverseNum(nums[i])] = i;
        }
        return res==INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {12,21,45,33,54};
    cout << s.minMirrorPairDistance(nums) << endl;
}
