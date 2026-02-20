#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        // 从第0层开始考虑，将鸡蛋分两种，第一个鸡蛋用来跨越大间隔，第二个鸡蛋用来在每一个间隔里面试探，所以如果我们多往上走一个间隔，第一个鸡蛋用的步数就会多1，为了保证每一个间隔步数平均，所以我们可以将下一个间隔减小1，于是所有间隔大小就如下：m, m-1, m-2, ... , 2, 1，这时候我们倒过来考虑，从最高层开始，第一次间隔为1，以后逐个递减，这样一直到到达最低端，那么所有间隔相加就是m*(m+1)/2，如果这个数字大于等于n，说明最小操作次数就是m，解方程即可
        return ceil((sqrt(1+8*n)-1)/2);
    }
};

int main(){
    Solution s;
    int n = 1000;
    cout << s.twoEggDrop(n) << endl;
}
