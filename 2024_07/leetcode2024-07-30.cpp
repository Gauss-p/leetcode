#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int my_pow(int x, int n, int m){
            int res = 1;
            // 该函数用快速幂的方法计算(x**n)%m的结果
            // 其中，计算x**n时，可以这样想，将n转换为二进制的形式，就可以分解成多个2的幂相加，也就是将乘方运算中的指数分解成多个数相加，可以看作多个乘方运算相乘
            // 例子：2**13 其中13可以写作1101，分解成1000+100+1，也就是(2**8)*(2**4)*(2**1)
            // 那么我们可以从x**1开始计算，如果n的末尾是1，就代表这个数字需要乘到答案中，接下来将n右移1位，对x**2进行计算……以此类推，就可以将其分解
            while (n){
                if (n & 1){
                    // 如果当前幂的末尾是1，就说明需要再乘一次
                    // 注意每一次计算需要再次取模，否则有可能超出int的限制
                    res *= x;
                    res = res%m;
                }
                x *= x;
                n = n >> 1;
            }
            return res;
        }
        int my_cal(int a, int b, int c){
            int res = 1;
            while (b--){
                res = (res*(a%c))%c;
            }
            return res;
        }
        vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
            vector<int> res;
            int n = variables.size();
            for (int i=0; i<n; i++){
                int first = my_pow(variables[i][0],variables[i][1],10);
                int second = my_pow(first, variables[i][2], variables[i][3]);
                if (second == target){
                    res.push_back(i);
                }
            }
            return res;
        }
};

int main(){
    Solution s;
    vector<vector<int>> variables = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
    int target = 2;
    vector<int> res = s.getGoodIndices(variables, target);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
