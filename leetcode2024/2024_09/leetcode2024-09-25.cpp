#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // 这道题目可以用传信号的方式计算有效的公司名字数目，首先用set将ideas去重，接下来定义mp，其中的键存两个值，两个值a,b分别存储ideas中有多少个单词的开头可以从b换成a并且不和其它单词重复，例如，如果我们发现将字符串str1="coffee"的第一个字母"c"改成"d"以后变成"doffee"，且"doffee"在ideas中没有出现过，我们就将mp["d c"]加上1，这样，只要之后的循环中我们发现某个字符串str2的开头是"d"并且将其开头换成"c"以后不会重复，那就说明str1和str2交换首字母后都不在ideas中，此时就将答案加上mp["d c"]即可。这很像传输信号，当我们发现将str1的首字母a换成b不会重复，就发出一个信号"b a"，之后如果有另外一个str2可以满足将首字母b换成a不会重复，就相当于接受信号，这时统计res即可
        // 最后要注意返回时res要乘以2，因为每一对(str1,str2)都可以互换形成一个新的有效名字
        long long res = 0;
        unordered_set<string> st(ideas.begin(), ideas.end());
        unordered_map<int, int> mp;
        for (string iword : ideas){
            for (char i='a'; i<='z'; i++){
                string new_word;
                new_word = i+iword.substr(1, iword.size()-1); // 换掉首字母
                if (st.count(new_word) == 0){
                    int key1 = iword[0]<<16 | i, key2 = i<<16 | iword[0];
                    res += mp[key1]; // 接受信号
                    mp[key2]++; // 发出信号
                }
            }
        }
        return res*2;
    }
};

int main(){
    Solution s;
    vector<string> ideas = {"coffee", "donuts", "time", "toffee"};
    cout << s.distinctNames(ideas) << endl;
}
