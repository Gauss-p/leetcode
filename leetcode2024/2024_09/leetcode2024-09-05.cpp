#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char> st;
        for (int i=0; i<n; i++){
            if (s[i] >= 'a' && s[i] <= 'z'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string res;
        while (!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main(){
    string s = "a1bc2";
    Solution so;
    cout << so.clearDigits(s) << endl;
}

/*3174. 清除数字
给你一个字符串 s 。
你的任务是重复以下操作删除 所有 数字字符：
删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
请你返回删除所有数字字符以后剩下的字符串。
*/
