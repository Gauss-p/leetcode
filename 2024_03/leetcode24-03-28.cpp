#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        // 根据题意，我们可以知道，如果第一次访问i，那么i之后都没有访问过，且i之前所有的房间都访问了偶数次
        // 那么定义f，f[i]表示第i个房间从奇数次访问到下一次变为偶数次访问所需要的最少天数
        // 再回到第一条，如果第一次访问i，那么上一次访问的一定是i-1
        // 即访问完i-1后，i-1号房间的次数变成了偶数
        // 并且访问i-1时没有访问过i，所以当前访问不可能是由后面元素跳转回来的，可以知道，i-2也应该是偶数
        // 以此类推，可以知道i之前所有房间都访问了偶数次
        // 接着，因为i是第一次访问，是奇数，下一次就应该访问nextVisit[i]的房间，令j=nextVisit[i]
        // 但是根据上面推出的，可以知道在访问j之前，它的次数是偶数，因此，在加上这一次访问后，就会变为奇数
        // 因此，如果还要继续访问i+1，就需要把j变成偶数，再把j+1变成偶数……一直到把i变成偶数，最后才能访问到i+1
        // 所以，f[i] = 1+f[j]+f[j+1]+f[j+2]+···+f[i-1]+1，其中，第一个1代表从i跳到j，第二个代表从变为偶数的i-1跳到i
        // 定义s，使得s[i] = f[0]+f[1]+···+f[i-1]，那么f[i] = s[i+1]-s[i]，且f[i] = s[i]-s[j]+2
        // 令两式相等，可知s[i+1] = s[i]*2-s[j]+2
        // 那么总共的天数就应该是：把0变成偶数的天数+把1变成偶数的天数+···+把n-2变成偶数的天数+1(最后访问n-1)
        //                     =f[0]+f[1]+f[2]+···+f[n-2]+1
        //                     =s[n-1]+1
        // 又因为天数是从0开始编号的，所以访问完所有房间的应该是第s[n-1]天
        int n = nextVisit.size(), mod_num = 1e9+7;
        vector<long long> s(n);
        s[0] = 0;
        for (int i=0; i<n-1; i++){
            int j = nextVisit[i];
            s[i+1] = (s[i]*2-s[j]+2+mod_num)%mod_num;
        }
        return s[n-1];
    }
};

int main(){
    Solution s;
    vector<int> nextVisit = {0, 0};
    cout << s.firstDayBeenInAllRooms(nextVisit) << endl;
}
