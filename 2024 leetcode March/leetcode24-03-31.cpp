#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // 如果该树中入度减去出度为0，那么就是一个合法二叉树
        int d = -1; // 由于根节点没有入度，所以为了统一，需要将d的初始值设置为-1
        stringstream ss(preorder); // 利用字符串流分割字符串
        string tmp;
        while (getline(ss, tmp, ',')){
            d++; // 无论哪个节点，入度都为1
            // 作为二叉树，如果没有循环到叶子节点，那么一定要保证任何时候入度要大于出度
            // 如果入度-出度大于0，就说明无法构成合法二叉树
            if (d > 0) return false;
            if (tmp != "#"){
                // 如果此时不为空节点，那么出度一定为2
                d -= 2;
            }
            // cout << tmp << " " << d << endl;
        }
        return d == 0;
    }
};

int main(){
    Solution s;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << s.isValidSerialization(preorder) << endl;
}
