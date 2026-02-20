#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    string str;
    int n, K;
    unordered_map<long long, int> memo;

    int myBitCount(int x){
        int res = 0;
        while (x){
            if (x&1){
                res++;
            }
            x >>= 1;
        }
        return res;
    }

    int dfs(int i, int mask, bool changed){
        if (i == n){
            return 1;
        }
        long long key = (long long)i << 32 | mask << 1 | changed;
        if (memo.count(key)){
            return memo[key];
        }
        int ans = 0;
        int bit = 1<<(str[i]-'a');
        int newMask = mask | bit;
        if (myBitCount(newMask) > K){
            ans = dfs(i+1, bit, changed)+1;
        }
        else{
            ans = dfs(i+1, newMask, changed);
        }
        if (!changed){
            for (int j=0; j<26; j++){
                if (j == str[i]-'a'){
                    continue;
                }
                int curBit = 1<<j;
                newMask = mask | curBit;
                if (myBitCount(newMask) > K){
                    ans = max(ans, dfs(i+1, curBit, true)+1);
                }
                else{
                    ans = max(ans, dfs(i+1, newMask, true));
                }
            }
        }
        memo[key] = ans;
        return ans;
    }
public:
    int maxPartitionsAfterOperations(string s, int k) {
        str = s;
        n = s.size();
        K = k;
        return dfs(0, 0, false);
    }
};

int main(){
    Solution sl;
    string s = "accca";
    int k = 2;
    cout << sl.maxPartitionsAfterOperations(s, k) << endl;
}
