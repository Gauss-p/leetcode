#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        int m = 32 - __builtin_clz(n);
        // 创建pa，使得pa[x][i]的意思是第x个节点的第2^i个祖先
        // 这样创建的依据是每一个数字都可以由若干个2的幂组成
        // 而这个命题的证明很简单：1、把一个数字用二进制表示
        //                       2、将每一位1带着后缀零单独提出来，就可以找到所需要的所有2的幂
        // 例如：10的二进制为1010，也就是1000+10，即8+2=2^3+2^1
        // 这样就可以通过不断用“第2^i个祖先”往上跳转，直到到达所需要的第k个祖先
        pa.resize(n, vector<int> (m, -1));
        // 首先将每一个节点的第2^0=1个祖先初始化为它的父亲
        for (int i=0; i<n; i++){
            pa[i][0] = parent[i];
        }
        for (int i=0; i<m-1; i++){
            for (int x=0; x<n; x++){
                int p = pa[x][i];
                // 如果p是-1，就说明就算继续增多“第k个祖先节点”中的k，答案也将是-1
                // 意思就是如果此时已经查到最顶端，那么就没有往上查的必要了
                if (p != -1){
                    pa[x][i+1] = pa[p][i];
                    // 第x个节点的第2^(i+1)个祖先为：它第2^i个祖先的第2^i个祖先
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int m = 32 - __builtin_clz(k);
        for (int i=0; i<m; i++){
            // 如果当前第i位是1，说明此时可以用pa中的数据，将node转成它第2^i个父节点
            // 以此类推，就可以用若干个“第2^i个父节点”算出“第k个父节点”
            if ((k >> i) & 1){ // 判断当前位是否为1
                node = pa[node][i]; // 不断向上跳转
                if (node < 0) break; // 如果查找到-1，说明无论k再大，都不会改变了
            }
        }
        return node;
    }

private:
    vector<vector<int>> pa;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main(){
    // TreeAncestor t;
    cout << __builtin_clz(4) << endl;
    return 0;
}
