#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        // 因为最开始给出的s是一个美丽字符串，所以我们需要找的只是下一个美丽字符串
        // 因为要保证答案的字典序最小，就要尽可能的加最右边的字符
        // 那么我们可以通过进位来解决超出限制的问题，就是把当前字符置为'a'，再将它前一个字符加1即可
        // 如果没有前一个，就返回空字符
        // 至于判断回文，就对每一个字符检查是否和它前两个字符相等即可
        k += 'a';
        int n = s.size();
        int i = n-1;
        s[i]++;
        while (i < n){
            if (s[i] == k){
                // 进位
                if (i == 0){
                    // 不能进位
                    return "";
                }
                // 完成进位
                s[i] = 'a';
                s[i-1]++;
                i--;
            }
            else if ((i>0 && s[i] == s[i-1]) || (i>1 && s[i] == s[i-2])){
                // 出现回文子串
                s[i]++;
            }
            else{
                i++;
            }
        }
        return s;
    }
};

int main(){
    Solution so;
    string s = "dcad";
    int k = 4;
    cout << so.smallestBeautifulString(s, k) << endl;
}
