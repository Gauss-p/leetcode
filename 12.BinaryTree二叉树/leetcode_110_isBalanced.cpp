#include <iostream>
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
    bool res;
    int dfs(TreeNode* node){
        if (!node){
            return 0;
        }
        int l = dfs(node->left);
        int r = dfs(node->right);
        if (abs(l-r) > 1){
            res = false;
        }
        return max(l, r)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        res = true;
        dfs(root);
        return res;
    }
};

int main(){
    vector<int> tot = {3,5,1,6,2,0,8,NULL,NULL,7,4};
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
    cout << s.isBalanced(root) << endl;
}
