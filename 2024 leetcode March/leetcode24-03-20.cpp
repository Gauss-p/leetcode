#include <iostream>
using namespace std;

class Solution {
public:
    long long mod_num = 1e9+7;
    int my_fast_power(long long n, int p){
        // pΪλ����������Ҫ�����ݵ����ֶ���������λ�þ�Ϊ1������ֻ��Ҫ�����˼���
        // �����λ�ö���1�����Կ���д��2^(p-1)+2^(p-2)+...+2^1+2^0����ʽ
        // �ٸ����ݵļ������,�Ϳ���֪��������Ϊ:
        // n^(2^(p-1))*n^(2^(p-2))*...*n^(2^1)*n^(2^0)
        n = n%mod_num;
        int res = 1;
        while (p--){
            res = (res*n)%mod_num;
            n = (n*n)%mod_num;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        if (p == 1) return 1;
        long long l = (1ll<<p)-1;
        long long res = my_fast_power(l-1, p-1)%mod_num;
        return (res%mod_num)*(l%mod_num)%mod_num;
    }
};

int main(){
    Solution s;
    int p = 36;
    cout << s.minNonZeroProduct(p) << endl;
}
