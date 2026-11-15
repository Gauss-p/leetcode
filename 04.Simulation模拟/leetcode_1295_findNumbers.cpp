#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i : nums){
            if (to_string(i).size()%2 == 0){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {12,345,2,6,7896};
    cout << s.findNumbers(nums) << endl;
}
