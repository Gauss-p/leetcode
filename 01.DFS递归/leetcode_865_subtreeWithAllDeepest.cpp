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
    TreeNode* res;
    int maxDepth;
    int dfs(TreeNode* node, int depth){
        if (!node){
            maxDepth = max(maxDepth, depth);
            return depth;
        }
        int leftDepth = dfs(node->left, depth+1);
        int rightDepth = dfs(node->right, depth+1);
        if (leftDepth == maxDepth && maxDepth == rightDepth){
            res = node;
        }
        return max(leftDepth, rightDepth);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = -1;
        dfs(root, 0);
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
    cout << s.subtreeWithAllDeepest(root)->val << endl;
}
