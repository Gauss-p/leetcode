#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& que, int x) {
        vector<int> indx;
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i] == x){
                indx.push_back(i);
            }
        }
        vector<int> res;
        for (auto i : que){
            if (i <= indx.size()){
                res.push_back(indx[i-1]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,1,7}, queries = {1,3,2,4};
    int x = 1;
    vector<int> res = s.occurrencesOfElement(nums, queries, x);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
}
