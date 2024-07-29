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
                // ������ü��꣬��ô����һ����Ч����ɷ�ʽ
                if (v.size() == k){
                    res.push_back(v);
                }
                return;
            }
            if (presentNum < lastSub){
                return;
            }
            for (int i : candy){
                // ����ܹ�����������ô�ͼ����ݹ飬����n
                // ����һ�μ�����֮�����������Ϊ�˷�ֹ�ظ�
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
