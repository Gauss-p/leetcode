#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // 计算以每个偶数结尾时，前面两个数字不同的排列数量
        // 首先考虑两个数字不同的情况，若当前剩下的不同数字有m个，那么此时前面两个数字不同排列的总数量就是m*(m-1)
        // 接下来是前两个数字相同的情况，那么循环所有剩余数字，如果其个数大于等于2，就累加1
        // 注意最后需要减去数字开头是0的所有数字，注意到当确定下数字最后一位的偶数时，开头是0的数字只有一位可以变化，故这样的数的总个数就是中间这一位总共可能填的数
        unordered_map<int, int> cnt;
        for (int i : digits) cnt[i]++;
        int m = cnt.size();
        if (cnt.count(0)){
            m -= 1;
        }
        int res = 0;
        for (int i=0; i<=8; i+=2){
            if (cnt.count(i) == 0) continue;
            cnt[i] -= 1;
            int nonZ = m-(i!=0 && cnt[i]==0), tot = cnt.size()-(cnt[i]==0);
            res += tot*(tot-1);
            for (int j=1; j<=9; j++){
                if (cnt.count(j) && cnt[j] >= 2){
                    res += 1;
                }
            }
            if (cnt.count(0) && cnt[0]){
                res -= nonZ;
            }
            cnt[i] += 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> digits = {1,2,3,4};
    cout << s.totalNumbers(digits) << endl;
}
