#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int n;
    vector<int> Nums;
    bool canBalanced(int length){
        unordered_map<int, int> odd, even;
        for (int i=0; i<n; i++){
            int x = Nums[i];
            if (x&1) odd[x]++;
            else even[x]++;
            
            if (i<length-1){
                continue;
            }
            if (odd.size() == even.size()){
                return true;
            }

            int last = Nums[i-length+1];
            if (last&1){
                odd[last]--;
                if (odd[last] == 0){
                    odd.erase(last);
                }
            }
            else{
                even[last]--;
                if (even[last] == 0){
                    even.erase(last);
                }
            }
        }
        return false;
    }
public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        Nums = nums;
        for (int l=n; l>=1; l--){
            if (canBalanced(l)){
                return l;
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,5,4,3};
    cout << s.longestBalanced(nums) << endl;
}
