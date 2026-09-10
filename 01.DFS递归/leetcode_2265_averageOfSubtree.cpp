#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> dfs(TreeNode* node){
        int curSum = node->val, cnt = 1, res = 0;
        if (node->left){
            auto nxt = dfs(node->left);
            curSum += nxt[0];
            cnt += nxt[1];
            res += nxt[2];
        }
        if (node->right){
            auto nxt = dfs(node->right);
            curSum += nxt[0];
            cnt += nxt[1];
            res += nxt[2];
        }
        res += (node->val == curSum/cnt);
        return {curSum, cnt, res};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        return dfs(root)[2];
    }
};

int main(){
    vector<int> tot = {4,8,5,0,1,NULL,6};
    function<TreeNode*(int)> dfs = [&](int indx){
        TreeNode* cur = new TreeNode(tot[indx]);
        if (indx*2+1 < tot.size() && tot[indx*2+1]){
            cur->left = dfs(indx*2+1);
        }
        if (indx*2+2 < tot.size() && tot[indx*2+2]){
            cur->right = dfs(indx*2+2);
        }
        return cur;
    };
    TreeNode* root = dfs(0);
    Solution s;
    cout << s.averageOfSubtree(root) << endl;
}
