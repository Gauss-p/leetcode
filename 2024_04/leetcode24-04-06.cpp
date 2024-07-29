#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        int m = 32 - __builtin_clz(n);
        // ����pa��ʹ��pa[x][i]����˼�ǵ�x���ڵ�ĵ�2^i������
        // ����������������ÿһ�����ֶ����������ɸ�2�������
        // ����������֤���ܼ򵥣�1����һ�������ö����Ʊ�ʾ
        //                       2����ÿһλ1���ź�׺�㵥����������Ϳ����ҵ�����Ҫ������2����
        // ���磺10�Ķ�����Ϊ1010��Ҳ����1000+10����8+2=2^3+2^1
        // �����Ϳ���ͨ�������á���2^i�����ȡ�������ת��ֱ����������Ҫ�ĵ�k������
        pa.resize(n, vector<int> (m, -1));
        // ���Ƚ�ÿһ���ڵ�ĵ�2^0=1�����ȳ�ʼ��Ϊ���ĸ���
        for (int i=0; i<n; i++){
            pa[i][0] = parent[i];
        }
        for (int i=0; i<m-1; i++){
            for (int x=0; x<n; x++){
                int p = pa[x][i];
                // ���p��-1����˵������������ࡰ��k�����Ƚڵ㡱�е�k����Ҳ����-1
                // ��˼���������ʱ�Ѿ��鵽��ˣ���ô��û�����ϲ�ı�Ҫ��
                if (p != -1){
                    pa[x][i+1] = pa[p][i];
                    // ��x���ڵ�ĵ�2^(i+1)������Ϊ������2^i�����ȵĵ�2^i������
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int m = 32 - __builtin_clz(k);
        for (int i=0; i<m; i++){
            // �����ǰ��iλ��1��˵����ʱ������pa�е����ݣ���nodeת������2^i�����ڵ�
            // �Դ����ƣ��Ϳ��������ɸ�����2^i�����ڵ㡱�������k�����ڵ㡱
            if ((k >> i) & 1){ // �жϵ�ǰλ�Ƿ�Ϊ1
                node = pa[node][i]; // ����������ת
                if (node < 0) break; // ������ҵ�-1��˵������k�ٴ󣬶�����ı���
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
