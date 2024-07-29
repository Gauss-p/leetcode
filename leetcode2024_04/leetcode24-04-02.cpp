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
        // ������������ִ�еݹ�
        // ������֪�����Ҫ�����������������һ��ҪΪ�������������������n��ż�����ͷ��ؿ�����
        // ����һ���������n=1�������Ϊ�ݹ������ʱΪn��Сֵ��ֻ��Ҫ����[[0]]����
        if (0 == (n & 1)) return {};
        if (n == 1){
            TreeNode* tmp = new TreeNode(0);
            return {tmp};
        }
        vector<TreeNode*> res;
        // ѭ���������Ĵ�С������ͬʱȷ���������Ĵ�С
        // ˼·�ǻ��������������������Լ������������������Ȼ��һһ��ԣ��Ϳ��Եõ���nΪ�������������
        // ��˫��ѭ���н�ÿһ���������𰸣���󷵻�
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
