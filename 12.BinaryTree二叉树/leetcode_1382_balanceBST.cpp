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
    vector<int> tot;
    void dfs(TreeNode* node){
        if (!node){
            return;
        }
        dfs(node->left);
        tot.push_back(node->val);
        dfs(node->right);
    }

    TreeNode* build(int l, int r){
        int mid = (l+r)/2;
        TreeNode* cur = new TreeNode(tot[mid]);
        if (l<mid){
            cur->left = build(l, mid-1);
        }
        if (mid<r){
            cur->right = build(mid+1, r);
        }
        return cur;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0, tot.size()-1);
    }
};

int main(){
    vector<int> tot = {1,NULL,2,NULL,3,NULL,4};
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
    cout << s.balanceBST(root)->val << endl;
}
