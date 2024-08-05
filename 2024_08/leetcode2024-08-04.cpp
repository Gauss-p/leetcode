#include <iostream>
#include <functional>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag = false;
        function<string(TreeNode*)> pre = [&](TreeNode* tree){
            string s = to_string(tree->val)+"-";
            if (tree->left){
                s += pre(tree->left);
            }
            if (tree->right){
                s += pre(tree->right);
            }
            return s;
        };
        function<string(TreeNode*)> mid = [&](TreeNode* tree){
            string s;
            if (tree->left){
                s = mid(tree->left);
            }
            s += to_string(tree->val)+"-";
            if (tree->right){
                s += mid(tree->right);
            }
            return s;
        };
        function<void(TreeNode*)> dfs = [&](TreeNode* tree){
            if (tree->val == subRoot->val){
                if (pre(tree) == pre(subRoot) && mid(tree) == mid(subRoot)){
                    flag = true;
                    return;
                }
            }
            if (tree->left){
                dfs(tree->left);
            }
            if (tree->right){
                dfs(tree->right);
            }
        };
        dfs(root);
        return flag;
    }
};

int main(){
    Solution s;
    TreeNode* tree1 = new TreeNode(3);
    TreeNode* tree2 = new TreeNode(4);
    TreeNode* root = tree1;
    TreeNode* subRoot = tree2;
    TreeNode* tmp1 = new TreeNode(1);
    TreeNode* tmp2 = new TreeNode(2);
    TreeNode* tmp3 = new TreeNode(5);
    tree2->left = tmp1;
    tree2->right = tmp2;
    tree1->left = tree2;
    tree1->right = tmp3;
    cout << s.isSubtree(root, subRoot) << endl;
}
