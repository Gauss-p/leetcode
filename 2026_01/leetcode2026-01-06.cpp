#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int res = 0;
        int depth = 1;
        while (!q.empty()){
            int cur = 0;
            int n = q.size();
            for (int i=0; i<n; i++){
                auto curNode = q.front();
                q.pop();
                cur += curNode->val;
                if (curNode->left){
                    q.push(curNode->left);
                }
                if (curNode->right){
                    q.push(curNode->right);
                }
            }
            if (cur > maxSum){
                maxSum = cur;
                res = depth;
            }
            depth++;
        }
        return res;
    }
};

int main(){
    vector<int> tot = {1,7,0,7,-8,NULL,NULL};
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
    cout << s.maxLevelSum(root) << endl;
}
