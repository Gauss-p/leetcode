#include <iostream>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        // 将一行中的所有情况分类，可以发现能够将它分成两种：ABA型和ABC型，每一类对应六种情况
        // 如果当前行填ABC型，下一行填ABC型，那么下一行共有2种填法
        // 如果当前行填ABC型，下一行填ABA型，那么下一行共有2种填法
        // 如果当前行填ABA型，下一行填ABC型，那么下一行共有2种填法
        // 如果当前行填ABA型，下一行填ABA型，那么下一行共有3种填法
        // 因此用0表示填ABC型，用1表示填ABA型，f[i][x](x为1或0)表示第i行填x型时，前i行共有多少种填法，即可得到：
        //      f[i][0] = 2*f[i-1][0]+2*f[i-1][1]
        //      f[i][1] = 2*f[i-1][0]+3*f[i-1][1]
        int modNum = 1e9+7;
        long long f0 = 6, f1 = 6;
        for (int i=1; i<n; i++){
            long long nextF0 = (2*f0+2*f1)%modNum;
            long long nextF1 = (2*f0+3*f1)%modNum;
            f0 = nextF0;
            f1 = nextF1;
        }
        return (f0+f1)%modNum;
    }
};

int main(){
    Solution s;
    int n = 2;
    cout << s.numOfWays(n) << endl;
}
