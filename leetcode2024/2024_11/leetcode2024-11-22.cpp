#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int makePrimeTable(int l, int r){
        // 用打表的方法，求出[1,r]中哪些是质数，这里我们可以用筛法，也就是从头开始遍历i，然后在范围[1,r]中将i的所有倍数都剔除出质数列表即可，这里我们定义素数列表prime，若prime[i]=1，则i为质数，否则i不为质数
        int end = sqrt(r), m = sqrt(l);
        vector<int> prime(end+1, 1);
        prime[1] = 0;
        for (int i=2; i<=end; i++){
            for (int j=i*i; j<=end; j+=i){
                // 剔除i的所有倍数
                prime[j] = 0;
            }
        }
        // 接下来统计答案，因为在这道题目中，我们称一个质数的完全平方数为特殊数字，所以在[l,r]内统计特殊数字的数量可以转换称在[sqrt(l),sqrt(r)]中统计质数的数量，因为：如果l为完全平方数，我们要从sqrt(l)开始统计，可如果l不是完全平方数，我们就要从sqrt(l)+1统计，所以：我们要对起始位置重新判断
        int begin = m;
        if (m*m != l){
            begin++;
        }
        int res = r-l+1;
        for (int i=begin; i<=end; i++){
            // 总数减去特殊数字的数量即为所求答案
            res -= prime[i];
        }
        return res;
    }
    // -------------------------------------------------------------------------------------------------
    int is_prime(int n){
        // 判断质数可以用循环，如果一个数在[2,sqrt(x)]内的因数个数为0，就是质数
        if (n < 2) return 0;
        for (int i=2; i<=(int)sqrt(n); i++){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    };
    int count_special(int n){
        // 用前缀和的方法，也就是用[0,r]中的特殊数字减去[0,l)中的特殊数字数量即可
        // 计算时可以用循环来计算。通过分析题目，可以发现，特殊数字就是一个质数的平方。所以计算特殊数字数量可以从2开始，只要是质数就判断其平方是否在需要的范围内，如果在，就加1，否则退出循环，返回统计的值即可
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
        // int special_num = count_special(r)-count_special(l-1);
        // return (r-l+1)-special_num;
        // -------------------------------------------------------
        return makePrimeTable(l, r);
    }
};

int main(){
    Solution s;
    int l = 1, r = 1e5;
    cout << s.nonSpecialCount(l, r) << endl;
}
