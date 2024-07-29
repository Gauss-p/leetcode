#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    vector<TreeNode*> allPossibleFBT(int n) {
        // 整个函数用来执行递归
        // 由题意知，如果要构成真二叉树，总数一定要为奇数，所以如果给出的n是偶数，就返回空向量
        // 对于一般情况，以n=1的情况作为递归基，此时为n最小值，只需要返回[[0]]即可
        if (0 == (n & 1)) return {};
        if (n == 1){
            TreeNode* tmp = new TreeNode(0);
            return {tmp};
        }
        vector<TreeNode*> res;
        // 循环左子树的大小，即可同时确定右子树的大小
        // 思路是获得左子树的所有情况，以及右子树的所有情况，然后一一配对，就可以得到以n为总数的所有情况
        // 在双重循环中将每一种情况加入答案，最后返回
        for (int i=1; i<n; i+=2){
            vector<TreeNode*> lt = allPossibleFBT(i);
            vector<TreeNode*> rt = allPossibleFBT(n-i-1);
            for (TreeNode* l : lt){
                for (TreeNode* r : rt){
                    TreeNode* tmp = new TreeNode(0, l, r);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 7;
    // for (auto i : s.allPossibleFBT(n)){
        // cout << i->val << endl;
    // }
    vector<TreeNode*> res = s.allPossibleFBT(n);
    cout << res.size();
}
