#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
private:
    // 用前缀和的方法，也就是用[0,r]中的特殊数字减去[0,l)中的特殊数字数量即可
    // 计算时可以用循环来计算。通过分析题目，可以发现，特殊数字就是一个质数的平方。所以计算特殊数字数量可以从2开始，只要是质数就判断其平方是否在需要的范围内，如果在，就加1，否则退出循环，返回统计的值即可
    // 判断质数可以用循环，如果一个数在[2,sqrt(x)]内的因数个数为0，就是质数
    int is_prime(int n){
        if (n < 2) return 0;
        for (int i=2; i<=(int)sqrt(n); i++){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    };
    int count_special(int n){
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
public:
    int nonSpecialCount(int l, int r) {
        int special_num = count_special(r)-count_special(l-1);
        return (r-l+1)-special_num;
    }
};

int main(){
    Solution s;
    int l = 1, r = 1e5;
    cout << s.nonSpecialCount(l, r) << endl;
}
