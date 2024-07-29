#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        // ��ǰ׺�͵ķ�����Ҳ������[0,r]�е��������ּ�ȥ[0,l)�е�����������������
        // ����ʱ������ѭ�������㡣ͨ��������Ŀ�����Է��֣��������־���һ��������ƽ�������Լ������������������Դ�2��ʼ��ֻҪ���������ж���ƽ���Ƿ�����Ҫ�ķ�Χ�ڣ�����ڣ��ͼ�1�������˳�ѭ��������ͳ�Ƶ�ֵ����
        // �ж�����������ѭ�������һ������[2,sqrt(x)]�ڵ���������Ϊ0����������
        function<int(int)> is_prime = [&](int n){
            if (n < 2) return 0;
            for (int i=2; i<=(int)sqrt(n); i++){
                if (n % i == 0){
                    return 0;
                }
            }
            return 1;
        };
        function<int(int)> count_special = [&](int n){
            int cnt = 0;
            int i = 2;
            while (i*i <= n){
                if (is_prime(i)){
                    cnt++;
                }
                i++;
            }
            return cnt;
        };
        int special_num = count_special(r)-count_special(l-1);
        return (r-l+1)-special_num;
    }
};

int main(){
    Solution s;
    int l = 4, r = 16;
    cout << s.nonSpecialCount(l, r) << endl;
}
