#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>
//~ #include <stddef.h>

using namespace std;

//~ Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
private:
    unordered_set<int> s;
public:
    FindElements(TreeNode* root) {
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int n){
            root->val = n;
            s.emplace(n);
            if (root->left) dfs(root->left, 2*n+1);
            if (root->right) dfs(root->right, 2*n+2);
        };
        dfs(root, 0);
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

TreeNode* buildtree(vector<int> array, int index){
    TreeNode* root = nullptr;
    int n = array.size();
    if (index < n && array[index]!=0)
    {
        root = new TreeNode(array[index]);
        root->left = buildtree(array, 2*index + 1);
        root->right = buildtree(array, 2*index + 2);
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode();
    vector<int> nodes = {-1,NULL,-1};
    int target = 1;
    root = buildtree(nodes, 0);
    FindElements* obj = new FindElements(root);
    bool param_1 = obj->find(target);
    cout << param_1 << endl;
    return 0;
}
