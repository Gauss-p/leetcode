#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i=0; i<n; i++){
            if (s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if (st.empty()){ // 这里需要保存最后一个无法配对的右括号，以便后面直接与栈顶元素相减得到对应长度
                    st.push(i);
                }
                res = max(res, i-st.top());
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    string s = "(()";
    cout << sl.longestValidParentheses(s) << endl;
}
