#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node{
    Node* son[26]{};
    Node* fail;
    int len = 0;
};

struct AhoCorasick{
public:
    // 建立AC自动机，AC自动机的关键在于它中间的fail指针，它指示我们如果查找失败以后可以从哪里继续查找，这样就能够节省时间，它应该主要用于处理查找重叠字符串中的单词
    // 里面一共两个函数，第一个put是用来创建树，但不创建fail指针，第二个函数是用来创建fail指针的，分三层处理，第一层一个节点，fail指针指向其自身，第二层26个节点，都指向root，第三层就是之后的所有节点，用一个BFS进行计算
    Node* root = new Node();
    void put(string s){
        auto cur = root;
        for (auto i : s){
            i -= 'a';
            if (cur->son[i] == nullptr){
                cur->son[i] = new Node();
                cur->son[i]->len = cur->len+1;
            }
            // 建树
            cur = cur->son[i];
        }
    }
    void build_fail(){
        root->fail = root; // 处理第0层的root的fail指针
        queue<Node*> q;
        for (int i=0; i<26; i++){
            // 处理第1层的所有fail指针
            auto &son = root->son[i];
            if (son == nullptr){
                son = root;
            }
            else{
                son->fail = root;
                q.push(son);
            }
        }
        // BFS计算之后所有节点的fail指针
        while (!q.empty()){
            auto cur = q.front();
            q.pop();
            for (int i=0; i<26; i++){
                auto& son = cur->son[i];
                if (son == nullptr){
                    son = cur->fail->son[i];
                    continue;
                }
                son->fail = cur->fail->son[i];
                q.push(son);
            }
        }
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        AhoCorasick ac;
        for (int i=0; i<words.size(); i++){
            ac.put(words[i]);
        }
        ac.build_fail();
        // 以上是创建AC自动机的树

        int n = target.size();
        vector<int> f(n+1, 0); // 定义动态规划，f[i]代表组成前i个字符的最小花费
        auto cur = ac.root, rt = ac.root;
        for (int i=1; i<=n; i++){
            cur = cur->son[target[i-1]-'a'];
            if (cur == rt){
                // 如果当前字符指向的还是根节点，说明无法构成target
                return -1;
            }
            f[i] = f[i-cur->len]+1;
        }
        return f[n];
    }
};

int main(){
    Solution s;
    vector<string> words = {"abc","aaaaa","bcdef"};
    string target = "aabcdabc";
    cout << s.minValidStrings(words, target) << endl;
}
