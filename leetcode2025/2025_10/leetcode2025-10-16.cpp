#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> cnt;
        for (int& i : nums){
            cnt[(i%value+value)%value]++;
        }
        int i = 0;
        while (true){
            if (cnt[i%value] == 0){
                return i;
            }
            cnt[i%value]--;
            i++;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,-10,7,13,6,8};
    int value = 5;
    cout << s.findSmallestInteger(nums, value) << endl;
}
