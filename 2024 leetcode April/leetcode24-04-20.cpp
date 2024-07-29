#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candy, int target) {
        sort(candy.begin(), candy.end());
        vector<vector<int>> res;
        function<void(int, int, vector<int>)> dfs = [&](int lastSub, int presentNum, vector<int> v){
            v.push_back(lastSub);
            if (presentNum == 0){
                res.push_back(v);
                return;
            }
            if (presentNum < lastSub){
                return;
            }
            for (int i : candy){
                if (i >= lastSub){
                    dfs(i, presentNum-i, v);
                }
            }
        };
        for (int i : candy){
            if (target-i == 0){
                res.push_back({i});
                break;
            }
            dfs(i, target-i, {});
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> candy = {2,3,4,7};
    int target = 7;
    vector<vector<int>> res = s.combinationSum(candy, target);
    for (auto i : res){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
