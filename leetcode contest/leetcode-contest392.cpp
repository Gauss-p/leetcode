#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution1 {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int up = 1, down = 1;
        int max_up = 1, max_down = 1;
        for (int i=1; i<n; i++){
            if (nums[i-1] >= nums[i]){
                max_up = max(max_up, up);
                up = 0;
            }
            up++;
        }
        max_up = max(max_up, up);
        for (int i=1; i<n; i++){
            if (nums[i-1] <= nums[i]){
                max_down = max(max_down, down);
                down = 0;
            }
            down++;
        }
        max_down = max(max_down, down);
        // cout << max_down << " " << max_up;
        return max(max_down, max_up);
    }
};

class Solution2 {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        int indx = 0;
        while (k > 0 && indx < n){
            char &cur = s[indx];
            if (cur <= 'm'){
                if (cur-'a' > k){
                    cur -= k;
                    break;
                }
                else{
                    k -= (cur-'a');
                    cur = 'a';
                }
            }
            else{
                if ('z'-cur+1 > k){
                    cur -= k;
                    break;
                }
                else{
                    k -= ('z'-cur+1);
                    cur = 'a';
                }
            }
            indx++;
        }
        return s;
    }
};

int main(){
    Solution1 s1;
    Solution2 s2;
}
