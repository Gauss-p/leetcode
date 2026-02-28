#include <iostream>
using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // 经过分析，可以发现我们要返回的答案一共只有两种情况，第一种是1，第二种是2
        // 返回1的一共有以下四种情况：
        // 1.如果车和皇后在同一列，并且象满足：要么不在当前列，要么在当前列但是没有挡在车和皇后中间
        // 2.如果车和皇后在同一行，并且象满足：要么不在当前行，要么在当前行但是没有挡在车和皇后中间
        // 3.如果象和皇后在同一个对角线上，并且车满足：要么不在当前对角线，要么在当前对角线但是没有挡在象和皇后的中间(对角线表示从左上到右下的对角线，可以用横纵坐标之差是否相等来判断两个点是否在同一个对角线)
        // 4.同情况三，但是这里对角线表示从右上到左下的对角线，可以用横纵坐标之和是否相等来判断两点是否在同一个对角线
        // 同时我们在判断a是否挡在b和c中间时可以判断a的横坐标是否小于b和c的横坐标的最小值，或者大于b和c的横坐标的最大值即可
        // 以下四个if分表表示四种情况
        if (a==e && (c!=e || (c==e && (d<min(b,f) || d>max(b,f))))){
            return 1;
        }
        if (b==f && (d!=f || (b==f && (c<min(a,e) || c>max(a,e))))){
            return 1;
        }
        if ((e-f==c-d) && ((b-a!=f-e) || (b-a==f-e && (a<min(c,e) || a>max(c,e))))){
            return 1;
        }
        if (e+f==c+d && (a+b!=e+f || (a+b==e+f && (a<min(c,e) || a>max(c,e))))){
            return 1;
        }
        return 2;
    }
};

int main(){
    Solution sl;
    int a = 5, b = 3, c = 3, d = 4, e = 5, f = 2;
    cout << sl.minMovesToCaptureTheQueen(a,b,c,d,e,f) << endl;
}
