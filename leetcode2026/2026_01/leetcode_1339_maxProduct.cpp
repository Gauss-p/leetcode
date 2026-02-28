#include <iostream>
#include <set>
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
    set<long long> tot;
    long long dfs(TreeNode* node){
        long long cur = node->val;
        if (node->left){
            cur += dfs(node->left);
        }
        if (node->right){
            cur += dfs(node->right);
        }
        tot.insert(cur);
        return cur;
    }
public:
    int maxProduct(TreeNode* root) {
        dfs(root);
        vector<long long> v(tot.begin(), tot.end());
        long long sumTree = v.back();
        int indx = lower_bound(v.begin(), v.end(), sumTree/2)-v.begin();
        int modNum = 1e9+7;
        return max((sumTree-v[indx])*v[indx], (sumTree-v[max(0, indx-1)])*v[max(0, indx-1)])%modNum;
    }
};

int main(){
    vector<int> tot = {1,2,3,4,5,6};
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
    cout << s.maxProduct(root) << endl;
}
