#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Node{
    Node* son[26]{};
    Node* fail;
    Node* last;
    int len = 0;
    int cost = INT_MAX;
};

struct AC{
public:
    // 建立AC自动机，AC自动机的关键在于它中间的fail指针，它指示我们如果查找失败以后可以从哪里继续查找，这样就能够节省时间，它应该主要用于处理查找重叠字符串中的单词，在本题中，我们需要再加入一个指针last，它的作用是指示当前节点
    // 的一个完整单词之前的节点，也就是它指示的节点和当前节点之间有一个完整的单词，方便主函数中的dp
    // 里面一共两个函数，第一个put是用来创建树，但不创建fail和last两个指针，第二个函数是用来创建fail和last指针的，分三层处理，第一层一个节点，fail指针指向其自身，第二层26个节点，都指向root，第三层就是之后的所有节点，用一个
    // BFS进行计算
    Node* root = new Node();
    void put(string s, int c){
        auto cur = root;
        for (auto i : s){
            i -= 'a';
            if (cur->son[i] == nullptr){
                cur->son[i] = new Node();
            }
            // 建树
            cur = cur->son[i];
        }
        cur->len = s.size();
        cur->cost = min(cur->cost, c); // 标识当前节点是否为单词结尾
    }
    void build_fail(){
        root->fail = root->last = root; // 处理第一层的root的fail指针
        queue<Node*> q;
        for (int i=0; i<26; i++){
            // 处理第二层的所有fail指针
            auto &son = root->son[i];
            if (son == nullptr){
                son = root;
            }
            else{
                son->fail = son->last = root;
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
                // --------------------以上是fail指针的计算，以下是last指针的计算
                if (son->fail->len){
                    son->last = son->fail;
                }
                else{
                    son->last = son->fail->last;
                }
                q.push(son);
            }
        }
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        AC ac;
        for (int i=0; i<words.size(); i++){
            ac.put(words[i], costs[i]);
        }
        ac.build_fail();
        // 以上是创建AC自动机的树

        int n = target.size();
        vector<int> f(n+1, INT_MAX/2); // 定义动态规划，f[i]代表组成前i个字符的最小花费
        f[0] = 0;
        auto cur = ac.root;
        for (int i=1; i<=n; i++){
            cur = cur->son[target[i-1]-'a'];
            if (cur->len){
                // 如果当前循环到的字符是一个完整单词的结尾，那么就用这个单词开头的花费加上完整单词的花费即可
                f[i] = min(f[i], f[i-cur->len]+cur->cost);
            }
            for (auto match = cur->last; match != ac.root; match = match->last){
                // 不断向前寻找上一个完整单词，并用该单词开头的花费加上后面所有完整单词的花费即可
                f[i] = min(f[i], f[i-match->len]+match->cost);
            }
        }
        // 如果依然是无穷大，就返回-1，否则返回f[n]，即组成前n个字符的最小花费
        return f[n]==INT_MAX/2 ? -1 : f[n];
    }
};

int main(){
    string target = "abcdef";
    vector<string> words = {"abdef","abc","d","def","ef"};
    vector<int> costs = {100,1,1,10,5};
    Solution s;
    cout << s.minimumCost(target, words, costs) << endl;
}
