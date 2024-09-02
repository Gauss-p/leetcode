#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        auto f = [&](auto&&f, char ch){
            int l = 0; // 用循环自动向后遍历右端点，这里直接定义一个左端点
            int res = 0;
            int cnt = 0; // 统计与ch不同的字符
            for (int r=0; r<n; r++){
                if (answerKey[r] != ch){
                    // 只要不相同，就统计一次
                    cnt++;
                }
                while (cnt > k){
                    // 如果不相同的字符数量超过了可以改变的字符数量k，就需要右移左端点
                    if (answerKey[l] != ch){
                        // 发现左边出现不相同的字符，就将cnt-1
                        cnt--;
                    }
                    l++; // 右移左端点
                }
                res = max(res, r-l+1); // 统计最大长度
            }
            return res;
        };
        return max(f(f, 'T'), f(f, 'F'));
    }
};

int main(){
    Solution s;
    string answerKey = "TTTTFTTTFTTTT";
    int k = 1;
    cout << s.maxConsecutiveAnswers(answerKey, k) << endl;
}
