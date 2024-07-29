/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> neibor;
        function<void(TreeNode*)> dfs = [&](TreeNode* tree){
            if (!tree) return;
            if (tree->left){
                neibor[tree->val].push_back(tree->left->val);
                neibor[tree->left->val].push_back(tree->val);
                dfs(tree->left);
            }
            if (tree->right){
                neibor[tree->val].push_back(tree->right->val);
                neibor[tree->right->val].push_back(tree->val);
                dfs(tree->right);
            }
        };
        dfs(root);
        int res = 0;
        vector<int> q;
        q.push_back(start);
        unordered_set<int> visited;
        visited.insert(start);
        while (q.size()){
            vector<int> q2;
            cout << res << endl;
            for (int i : q){
                for (int j : neibor[i]){
                    if (visited.count(j) != 1){
                        q2.push_back(j);
                        visited.insert(j);
                    }
                }
            }
            q = q2;
            res++;
        }
        return res-1;
    }
};
