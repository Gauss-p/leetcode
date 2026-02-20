#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candy = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        function<void(int, int, vector<int>)> dfs = [&](int lastSub, int presentNum, vector<int> v){
            v.push_back(lastSub);
            presentNum -= lastSub;
            if (presentNum == 0){
                // 如果正好减完，那么这是一个有效的组成方式
                if (v.size() == k){
                    res.push_back(v);
                }
                return;
            }
            if (presentNum < lastSub){
                return;
            }
            for (int i : candy){
                // 如果能够继续减，那么就继续递归，减少n
                // 从上一次减的数之后继续减，是为了防止重复
                if (i > lastSub){
                    dfs(i, presentNum, v);
                }
            }
        };
        for (int i : candy){
            dfs(i, n, {});
        }
        return res;
    }
};
