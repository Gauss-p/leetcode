#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(vector<double> nums){
        if (nums.size() == 1){
            return abs(nums[0]-24) <= 1e-9;
        }

        bool ans = false;
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                vector<double> cur = nums;
                cur.erase(cur.begin()+j);
                cur.erase(cur.begin()+i);

                cur.push_back(nums[i]+nums[j]);
                ans = ans | dfs(cur);
                cur.pop_back();

                cur.push_back(nums[i]-nums[j]);
                ans = ans | dfs(cur);
                cur.pop_back();

                cur.push_back(nums[j]-nums[i]);
                ans = ans | dfs(cur);
                cur.pop_back();

                cur.push_back(nums[i]*nums[j]);
                ans = ans | dfs(cur);
                cur.pop_back();

                if (nums[j] != 0){
                    cur.push_back(nums[i]*1.0/nums[j]);
                    ans = ans | dfs(cur);
                    cur.pop_back();
                }
                if (nums[i] != 0){
                    cur.push_back(nums[j]*1.0/nums[i]);
                    ans = ans | dfs(cur);
                    cur.pop_back();
                }

                if (ans){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int i : cards){
            nums.push_back(i*1.0);
        }
        return dfs(nums);
    }
};

int main(){
    Solution s;
    vector<int> cards = {4,1,8,7};
    cout << s.judgePoint24(cards) << endl;
}
