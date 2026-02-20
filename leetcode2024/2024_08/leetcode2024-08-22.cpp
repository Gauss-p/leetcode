#include <iostream>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        // 通过研究测试用例可以发现，数组的第一个数，也就是最小的数字必须是x，接下来就对x的二进制中的零位进行操作，将1，2，3……的二进制依次填入x的二进制零位中即可，又因为数组一共有n个数，所以最后一个数字就是将n-1的二进制依次填入x的零位中即可
        n--;
        int i = 0,j = 0;
        long long res = x;
        while ((n >> i)>0){
            if (((res >> j)&1) == 0){
                // 发现x中的一个0位，就填入n-1中轮到的数值
                res |= (long long)((n>>i)&1)<<j; 
                // 填了一个n-1中的数，就将n-1右移的位数再加1
                i++;
            }
            // 无论如何，都要将x右移的位数加1
            j++;
        }
        return res;
    }
};

int main(){
    int n = 3, x = 4;
    Solution s;
    cout << s.minEnd(n, x) << endl;
}
