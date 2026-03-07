#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        // 可以更简单地依据相邻元素的索引奇偶性不同，创建一个字符串target="01"，这样只需要用target[i%2]即可得到在索引为i的位置应当是什么元素，而想要知道另一种target匹配出来的操作次数，直接用s的长度减去当前操作次数即可
        // 接下来，同样可以直接用滑动窗口的方式进行模拟，先按照target求出将整个s变成交替字符串的操作次数，然后，为了模拟所有可能的操作1，可以依次对于每一个位置i，将其在原字符串中删除，并将其再加到第i+len(s)的位置，即将s[i]需要匹配的元素从target[i%2]变为target[(i+n)%2]即可
        int n = s.size();
        string target = "01";

        int cnt = 0;
        for (int i=0; i<n; i++){
            cnt += (s[i] != target[i%2]);
        }
        int res = min(cnt, n-cnt);

        for (int i=0; i<n; i++){
            cnt -= (s[i] != target[i%2]);
            cnt += (s[i] != target[(i+n)%2]);
            res = min(res, min(cnt, n-cnt));
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "111000";
    cout << sl.minFlips(s) << endl;
}
