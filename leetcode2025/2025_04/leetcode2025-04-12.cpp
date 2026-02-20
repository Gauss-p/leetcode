#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    long long myFactorial(int x){
        long long ans = 1;
        for (int i=2; i<=x; i++){
            ans *= i;
        }
        return ans;
    }
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        int m = (n-1)/2;
        for (int i=pow(10, m); i<pow(10, m+1); i++){
            string tmpStr = to_string(i);
            string rev = tmpStr;
            reverse(rev.begin(), rev.end());
            string newNum = tmpStr + rev.substr(n%2, n-n%2);
            long long intNum = stoll(newNum);
            if (intNum%k != 0){
                continue;
            }
            sort(newNum.begin(), newNum.end());
            st.insert(newNum);
        }
        
        long long res = 0;
        vector<string> v(st.begin(), st.end());
        for (string i : v){
            unordered_map<char, int> mp;
            for (char j : i){
                mp[j]++;
            }
            long long sum1 = 1ll*(n-mp['0'])*myFactorial(n-1);
            for (auto&kv : mp){
                sum1 = sum1/myFactorial(kv.second);
            }
            res += sum1;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 3, k = 5;
    cout << s.countGoodIntegers(n, k) << endl;
}
