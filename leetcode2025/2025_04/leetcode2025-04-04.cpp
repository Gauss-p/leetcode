#include <iostream>
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
    int maxDepth;
    TreeNode* res;
    int dfs(TreeNode* x, int depth){
        if (x == nullptr){
            maxDepth = max(maxDepth, depth);
            return depth;
        }
        int leftMD = dfs(x->left, depth+1);
        int rightMD = dfs(x->right, depth+1);
        if (leftMD == rightMD && leftMD == maxDepth){
            res = x;
        }
        return max(leftMD, rightMD);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxDepth = 0;
        dfs(root, 0);
        return res;
    }
};

int main(){
    Solution s;
    TreeNode* lr = new TreeNode(2);
    TreeNode* l = new TreeNode(1, nullptr, lr);
    TreeNode* r = new TreeNode(3);
    TreeNode* root = new TreeNode(0, l, r);
    cout << s.lcaDeepestLeaves(root)->val << endl;
}
