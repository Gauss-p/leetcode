#include <iostream>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        if (n == 0 || n == 1) return n+1;
        // 因为后边的代码对于二进制数字长度等于1的数字无法处理，故加入上面代码
        int length = 0;
        while (n >> length){
            length++;
        }
        // 以上代码用于计算给出的n的二进制数字位数，根据观察，我们可以发现规律，二进制位数为1的数字中，合法的数字最多有2个，位数为2的数字中，合法数字最多3个，3->5，4->8……以此类推，也就是说，如果一个数字n的二进制位数为l，那么[0,n]中的合法数字最多只有F(l+2)(斐波那契数列的第l个数)个，下面计算F(l+2)和F(l+1)
        int first = 1, second = 1;
        for (int _=0; _<length; _++){
            int tmp = first+second;
            first = second;
            second = tmp;
        }
        int res;
        if (length >= 2 && ((n >> (length-2))&1)){
            // 如果给出的数字n二进制数的前两位都是1，那么最终的答案就是F(l+2)
            return second;
        }
        if (abs(n-(1<<(length-1))) < abs(n-(1<<(length-2)))){
            // 否则，看一下n更靠近哪一个已知数，如果n靠近较小的数字，也就是(1<<(l-2))，那么就从这个数开始循环到n，只要有合法数字就加入答案(答案初始值即为F(l+1))
            res = first;
            for (int i=(1<<(length-1)); i<=n; i++){
                if ((i & (i<<1)) == 0){
                    res++;
                }
            }
        }
        else{
            // 如果靠近另外一边，就按同样方法处理
            res = second;
            for (int i=n; i<(1<<length); i++){
                if ((i & (i<<1)) == 0){
                    res--;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 1000000000;
    cout << s.findIntegers(n) << endl;
}
