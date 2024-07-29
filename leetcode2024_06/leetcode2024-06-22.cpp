#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        // ��Ϊ�ʼ������s��һ�������ַ���������������Ҫ�ҵ�ֻ����һ�������ַ���
        // ��ΪҪ��֤�𰸵��ֵ�����С����Ҫ�����ܵļ����ұߵ��ַ�
        // ��ô���ǿ���ͨ����λ������������Ƶ����⣬���ǰѵ�ǰ�ַ���Ϊ'a'���ٽ���ǰһ���ַ���1����
        // ���û��ǰһ�����ͷ��ؿ��ַ�
        // �����жϻ��ģ��Ͷ�ÿһ���ַ�����Ƿ����ǰ�����ַ���ȼ���
        k += 'a';
        int n = s.size();
        int i = n-1;
        s[i]++;
        while (i < n){
            if (s[i] == k){
                // ��λ
                if (i == 0){
                    // ���ܽ�λ
                    return "";
                }
                // ��ɽ�λ
                s[i] = 'a';
                s[i-1]++;
                i--;
            }
            else if ((i>0 && s[i] == s[i-1]) || (i>1 && s[i] == s[i-2])){
                // ���ֻ����Ӵ�
                s[i]++;
            }
            else{
                i++;
            }
        }
        return s;
    }
};

int main(){
    Solution so;
    string s = "dcad";
    int k = 4;
    cout << so.smallestBeautifulString(s, k) << endl;
}
