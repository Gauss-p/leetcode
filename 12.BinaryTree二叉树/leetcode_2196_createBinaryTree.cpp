#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> node;
        int root = 0;
        for (auto& d : descriptions){
            int p = d[0], c = d[1], l = d[2];
            if (node.count(p) == 0){
                node[p] = new TreeNode(p);
                root ^= p;
            }
            if (node.count(c) == 0){
                node[c] = new TreeNode(c);
                root ^= c;
            }
            if (l){
                node[p]->left = node[c];
            }
            else{
                node[p]->right = node[c];
            }
            root ^= c;
        }
        return node[root];
    }
};

int main(){
    Solution s;
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    cout << s.createBinaryTree(descriptions)->val << endl;
}
