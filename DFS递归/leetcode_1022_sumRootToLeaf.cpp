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
    int dfs(TreeNode* node, int cur){
        if ((!node->left) && (!node->right)){
            return cur;
        }
        int res = 0;
        if (node->left){
            res += dfs(node->left, cur<<1 | node->left->val);
        }
        if (node->right){
            res += dfs(node->right, cur<<1 | node->right->val);
        }
        return res;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, root->val);
    }
};

int main(){
    vector<int> tot = {1,0,1,0,1,0,1};
    function<TreeNode*(int)> dfs = [&](int indx){
        TreeNode* cur = new TreeNode(tot[indx]);
        if (indx*2+1 < tot.size() && tot[indx*2+1]>=0){
            cur->left = dfs(indx*2+1);
        }
        if (indx*2+2 < tot.size() && tot[indx*2+2]>=0){
            cur->right = dfs(indx*2+2);
        }
        return cur;
    };
    TreeNode* root = dfs(0);
    Solution s;
    cout << s.sumRootToLeaf(root) << endl;
}
