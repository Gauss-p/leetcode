#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // �����������ȼ�ȥ����Ϊ0����ô����һ���Ϸ�������
        int d = -1; // ���ڸ��ڵ�û����ȣ�����Ϊ��ͳһ����Ҫ��d�ĳ�ʼֵ����Ϊ-1
        stringstream ss(preorder); // �����ַ������ָ��ַ���
        string tmp;
        while (getline(ss, tmp, ',')){
            d++; // �����ĸ��ڵ㣬��ȶ�Ϊ1
            // ��Ϊ�����������û��ѭ����Ҷ�ӽڵ㣬��ôһ��Ҫ��֤�κ�ʱ�����Ҫ���ڳ���
            // ������-���ȴ���0����˵���޷����ɺϷ�������
            if (d > 0) return false;
            if (tmp != "#"){
                // �����ʱ��Ϊ�սڵ㣬��ô����һ��Ϊ2
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
