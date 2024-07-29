#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> c(26);
        for (auto &i : word){
            c[i-'a']++;
        }
        sort(c.begin(), c.end());
        // 前置差用来存储较小，并且需要减去的数
        int res = 1e6, front_sub = 0;
        for (auto &i : c){
            if (i == 0) continue;
            // int min_num = i;
            // 如果最底下那条线是i，那么如果要保证数据波动幅度小于或等于k，就要保证数据上限为i+k
            int max_limit = i+k;
            // 后置差用来存储后面较大数据需要减去的数
            int back_sub = 0;
            for (auto &j : c){
                if (j > max_limit){
                    back_sub += j-max_limit;
                }
            }
            // 每次算出来以后，就计算一下最小的答案
            res = min(res, front_sub+back_sub);
            // 如果以后面一个大一点的数为最小值，此时前置差就得加上当前这个数
            front_sub += i;
        }
        return res;
    }
};

int main(){
    string word = "dabdcbdcdcd";
    int k = 2;
    Solution s;
    cout << s.minimumDeletions(word, k) << endl;
    return 0;
}
