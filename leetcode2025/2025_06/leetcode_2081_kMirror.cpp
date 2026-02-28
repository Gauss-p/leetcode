#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MAX_NUM = 30;
vector<vector<long long>> ans(10, vector<long long>(1, 0ll));

bool check(long long x, int k){
    if (x%k == 0){
        return false;
    }
    long long half = 0;
    while (half<x){
        half = half*k+(x%k);
        x /= k;
    }
    return half==x || half/k==x;
}

bool pre_finished(long long x){
    bool done = true;
    for (int k=2; k<=9; k++){
        if (ans[k].size()<MAX_NUM+1 && check(x, k)){
            ans[k].push_back(ans[k][ans[k].size()-1]+x);
        }
        if (ans[k].size()<MAX_NUM+1){
            done = false;
        }
    }
    return done;
}

string myReverse(string a, int op){
    string b;
    for (int i=(int)a.size()-1-op; i>=0; i--){
        b += a[i];
    }
    return b;
}

void init(){
    // 在生成十进制回文数时可以直接对数字进行生成，也可以利用我自己编写的函数进行翻转字符串
    int base = 1;
    while (true){
        for (int cur=base; cur<base*10; cur++){
            // long long x = cur;
            // for (int t=cur/10; t>0; t/=10){
            //     x = x*10+t%10;
            // }
            // if (pre_finished(x)){
            //     return;
            // }
            string newN = to_string(cur);
            newN += myReverse(newN, 1);
            if (pre_finished(stoll(newN))){
                return;
            }
        }
        for (int cur=base; cur<base*10; cur++){
            // long long x = cur;
            // for (int t=cur; t>0; t/=10){
            //     x = x*10+t%10;
            // }
            // if (pre_finished(x)){
            //     return;
            // }
            string newN = to_string(cur);
            newN += myReverse(newN, 0);
            if (pre_finished(stoll(newN))){
                return;
            }
        }
        base *= 10;
    }
}

class Solution {
public:
    long long kMirror(int k, int n) {
        init();
        return ans[k][n];
    }
};

int main(){
    Solution s;
    int k = 2, n = 5;
    cout << s.kMirror(k, n) << endl;
}
