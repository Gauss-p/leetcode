#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        // 我们发现，x只能一个一个拿，y只能四个四个拿，所以我们将y/4变成z，也就求出了在y中能拿的最大次数，在y中四个四个拿就转换成在z中一个一个拿，所以最多能拿的次数就是x和z的最小值
        // 如果总共能拿的次数是偶数，那么Bob赢，否则Alice赢
        int mx = min(x, y/4);
        if ((mx & 1) == 0){
            return "Bob";
        }
        else{
            return "Alice";
        }
    }
};

int main(){
    Solution s;
    int x = 2, y = 7;
    cout << s.losingPlayer(x, y) << endl;
}
