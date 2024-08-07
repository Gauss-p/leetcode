#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        // 首先我们定义f[i][j][k]表示用i个0，j个1组成的合法数字再在最后一位加上k所能够形成的合法数组的个数，那么我们可以得到，k的值要么是0，要么是1
        // 继续分析递推式，f[i][j][0]的值就是用i个0，j个1组成的合法数组最后再加上0能形成的合法数组个数，那么反推前一位，也就是第i+j-1位上的数字有两种可能，要么是0，要么是1，这两种情况的和就是f[i-1][j][0]+f[i-1][j][1]其中i减了1是>因为最后一位要再多用一个0。但是又有一种情况，就是如果f[i-1][j][0]这种情况中有部分数字最后有连续limit个0，那如果再加一个0，就不合法了，所以说，还要再减去这种情况，而这种情况的总数就是f[i-limit-1][j][1]，之所以最后填1，是因为最后如果有连续limit个0，而它又合法，那么倒数limit+1位上的数字必然是1，由上面的分析可以得出，如果i>limit，那么f[i][j][0] = f[i-1][j][0]+f[i-1][j][1]-f[i-limit-1][j][1]，否则f[i][j][0]=f[i-1][j][0]+f[i-1][j][1]
        // 同理可知，当j>limit时，f[i][j][1] = f[i][j-1][0]+f[i][j-1][1]-f[i][j-limit-1][0]，否则，f[i][j][1] = f[i][j-1][0]+f[i][j-1][1]
        // 其中，我们还需要设置边界条件，也就是f[i][0][0] = 1(1<=i<=min(limit,zero))，f[0][j][1] = 1(1<=j<=min(limit,one))其中第一条的意思是，如果已经有在限制内的多个0，再追加1个0只有一种情况，第二条的意思是，如果已经有在限制内的多个1，再追加1个1只有一种情况
        vector<vector<array<int, 2>>> f(zero+1, vector<array<int, 2>>(one+1));
        for (int i=1; i<=min(limit, zero); i++){
            f[i][0][0] = 1;
        }
        for (int j=1; j<=min(limit, one); j++){
            f[0][j][1] = 1;
        }
        int mod_num = 1e9+7;
        for (int i=1; i<=zero; i++){
            for (int j=1; j<=one; j++){
                f[i][j][0] = ((long long) f[i-1][j][0]+f[i-1][j][1])%mod_num;
                if (i > limit){
                    f[i][j][0] = ((long long)f[i][j][0]-f[i-limit-1][j][1]+mod_num)%mod_num;
                }
                f[i][j][1] = ((long long) f[i][j-1][0]+f[i][j-1][1])%mod_num;
                if (j > limit){
                    f[i][j][1] = ((long long) f[i][j][1]-f[i][j-limit-1][0]+mod_num)%mod_num;
                }
            }
        }
        int res = (f[zero][one][0]+f[zero][one][1])%mod_num;
        return res;
    }
};

int main(){
    Solution s;
    int zero = 3, one = 3, limit = 2;
    cout << s.numberOfStableArrays(zero, one, limit) << endl;
}
