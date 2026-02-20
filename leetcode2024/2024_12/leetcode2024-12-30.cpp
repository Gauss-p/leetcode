#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* createTree(TreeNode* root, vector<int> v, int i){
        if (i < v.size()){
            if (v[i] == -1){
                return nullptr;
            }
            else{
                root = new TreeNode(v[i]);
                root->left = createTree(root->left, v, i*2+1);
                root->right = createTree(root->right, v, i*2+2);
                return root;
            }
        }
        return root;
    }

    bool dfs(ListNode* h, TreeNode* x){
        if (!h){
            return true;
        }
        if (!x){
            return false;
        }
        if (h->val != x->val){
            return false;
        }
        bool l = dfs(h->next, x->left);
        bool r = dfs(h->next, x->right);
        return (l|r);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root){
            return false;
        }
        return (dfs(head, root) | isSubPath(head, root->left) | isSubPath(head, root->right));
    }
};

int main(){
    Solution s;
    ListNode* ls = new ListNode(4);
    ListNode* head = ls;
    vector<int> chain = {2,8};
    for (int i : chain){
        ListNode* tmp = new ListNode(i);
        ls->next = tmp;
        ls = ls->next;
    }
    vector<int> v = {1,4,4,-1,2,2,-1,1,-1,6,8,-1,-1,-1,-1,1,3};
    TreeNode* root = s.createTree(nullptr, v, 0);
    cout << s.isSubPath(head, root) << endl;
}
