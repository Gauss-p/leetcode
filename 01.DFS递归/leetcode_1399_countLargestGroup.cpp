#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int m;
    vector<int> strN;
    int dfs(int s, int pos, bool limited){
        if (pos == m){
            if (s == 0){
                return 1;
            }
            return 0;
        }

        int ans = 0;
        int mx = (limited ? strN[pos] : 9);
        for (int i=0; i<=min(mx, s); i++){
            ans += dfs(s-i, pos+1, limited&(i == mx));
        }
        return ans;
    }
public:
    int countLargestGroup(int n) {
        m = 0;
        while (n>0){
            strN.insert(strN.begin(), n%10);
            n /= 10;
            m++;
        }

        int maxCnt = 0, res = 0;
        for (int i=1; i<m*9; i++){
            int tmpCnt = dfs(i, 0, true);
            if (tmpCnt>maxCnt){
                res = 1;
                maxCnt = tmpCnt;
            }
            else if (tmpCnt == maxCnt){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 13;
    cout << s.countLargestGroup(n) << endl;
}
