#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        // 定义calcN(times, eggs)函数用来计算在总共操作times次并且总鸡蛋数量为eggs时能够测得的最大楼层f，那么我们也可以将该最大楼层视为能确定f确切值的最大总楼层。
        // 通过计算我们可以发现，每一次在第x楼扔鸡蛋有两种情况，第一种是鸡蛋碎了，这时该鸡蛋就不能继续使用，第二种是鸡蛋没有碎，这时该鸡蛋还能继续使用，那么第一种情况发生时eggs就需要减1，而第二种情况发生时eggs不变。如果没有碎，那么就说明还能继续往上走，如果碎了，就说明需要往下走，这就是从x楼开始分别向上和向下进行计算，两个情况相加就是总楼层数量。也就是说，对于每一种情况，calcN(times, eggs)都可以视为calcN(times-1, eggs-1)+calcN(times-1, eggs)其中times减1是因为在第x楼扔了一次。
        // 接着考虑递归基，我们发现，当剩余机会times=1时，我们最多只能测出两层楼的准确值，而当剩余鸡蛋eggs=1时，我们最多只能测出times+1层楼的准确楼层，所以通过观察我们发现，只要times和eggs中有一个为1，那么就可以直接返回times+1
        // 当给出的次数能够在使用eggs个鸡蛋的情况下测出比n更高的掉落会碎的楼层f，这时求出次数的最小值即可。因为要求最小值，所以我们直接设定一个初始答案res=1，然后依次增加，直到出现第一个calc(res, k)的返回值大于等于n时就返回答案。
        auto calcN = [&](auto&&calcN, int times, int eggs){
            if (times == 1 || eggs == 1){
                return times+1;
            }
            return calcN(calcN, times-1, eggs)+calcN(calcN, times-1, eggs-1);
        };
        int res = 1;
        while (calcN(calcN, res, k) <= n){
            res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    int k = 6, n = 10;
    cout << s.superEggDrop(k, n) << endl;
}
