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
    // ����AC�Զ�����AC�Զ����Ĺؼ��������м��failָ�룬��ָʾ�����������ʧ���Ժ���Դ�����������ң��������ܹ���ʡʱ�䣬��Ӧ����Ҫ���ڴ�������ص��ַ����еĵ��ʣ��ڱ����У�������Ҫ�ټ���һ��ָ��last������������ָʾ��ǰ�ڵ�
    // ��һ����������֮ǰ�Ľڵ㣬Ҳ������ָʾ�Ľڵ�͵�ǰ�ڵ�֮����һ�������ĵ��ʣ������������е�dp
    // ����һ��������������һ��put����������������������fail��last����ָ�룬�ڶ�����������������fail��lastָ��ģ������㴦����һ��һ���ڵ㣬failָ��ָ���������ڶ���26���ڵ㣬��ָ��root�����������֮������нڵ㣬��һ��
    // BFS���м���
    Node* root = new Node();
    void put(string s, int c){
        auto cur = root;
        for (auto i : s){
            i -= 'a';
            if (cur->son[i] == nullptr){
                cur->son[i] = new Node();
            }
            // ����
            cur = cur->son[i];
        }
        cur->len = s.size();
        cur->cost = min(cur->cost, c); // ��ʶ��ǰ�ڵ��Ƿ�Ϊ���ʽ�β
    }
    void build_fail(){
        root->fail = root->last = root; // �����һ���root��failָ��
        queue<Node*> q;
        for (int i=0; i<26; i++){
            // ����ڶ��������failָ��
            auto &son = root->son[i];
            if (son == nullptr){
                son = root;
            }
            else{
                son->fail = son->last = root;
                q.push(son);
            }
        }
        // BFS����֮�����нڵ��failָ��
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
                // --------------------������failָ��ļ��㣬������lastָ��ļ���
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
        // �����Ǵ���AC�Զ�������

        int n = target.size();
        vector<int> f(n+1, INT_MAX/2); // ���嶯̬�滮��f[i]�������ǰi���ַ�����С����
        f[0] = 0;
        auto cur = ac.root;
        for (int i=1; i<=n; i++){
            cur = cur->son[target[i-1]-'a'];
            if (cur->len){
                // �����ǰѭ�������ַ���һ���������ʵĽ�β����ô����������ʿ�ͷ�Ļ��Ѽ����������ʵĻ��Ѽ���
                f[i] = min(f[i], f[i-cur->len]+cur->cost);
            }
            for (auto match = cur->last; match != ac.root; match = match->last){
                // ������ǰѰ����һ���������ʣ����øõ��ʿ�ͷ�Ļ��Ѽ��Ϻ��������������ʵĻ��Ѽ���
                f[i] = min(f[i], f[i-match->len]+match->cost);
            }
        }
        // �����Ȼ������󣬾ͷ���-1�����򷵻�f[n]�������ǰn���ַ�����С����
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
