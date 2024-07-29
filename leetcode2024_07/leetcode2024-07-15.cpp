#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class QuickUnionFindSet {
private:
    vector<int> roots;
public:
    // 创建并查集其实只需要一个列表就行了，其中每一个索引指向它的老大，也就是它归属的索引，这样就可以将每一个集合看作由其中的部分元素组成的连通块了
    // 并查集需要实现三个操作：查找根节点，判断两个元素是否属于同一个集合，以及合并两个元素所在的集合
    // 对于第一个操作，我们可以对传入的索引不断的向上追朔，一直到整个集合的最顶端，就找到了当前索引所属集合的根节点，但是我们可以进行优化，也就是每一次都将该集合中所有的元素直接指向最顶端的根节点，这样就更便捷
    // 对于第二个操作，直接判断两个节点所属集合的根节点是否相同即可
    // 对于第三个操作，直接将第一个索引的根节点指向第二个索引的根节点就可以实现两个集合之间的合并了
    QuickUnionFindSet(int n){
        roots.resize(n);
        for (int i=0; i<n; i++){
            roots[i] = i;
        }
    }
    int FindRoot(int i){
        int root = i;
        while (root != roots[root]){
            root = roots[root];
        }
        while (i != roots[i]){
            int tmp = roots[i];
            roots[i] = root;
            i = tmp;
        }
        return root;
    }
    bool Equal(int x, int y){
        return FindRoot(x) == FindRoot(y);
    }
    void Union(int x, int y){
        int xroot = FindRoot(x);
        int yroot = FindRoot(y);
        roots[xroot] = yroot;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 首先我们定义一个并查集的类，接下来将这道题目转化为可以用并查集求解的问题
        // 利用并查集可以快速合并两元素所在集合的特性，我们可以将原列表中的各个人名用索引来代替，然后，如果发现两个不同的索引对应有一个相同的邮箱地址，就直接合并两个索引，让它们指向一个人即可
        // 这样对所有元素进行操作以后，就会出现有许多不同的索引真正指向的是一个人，然后我们再反向操作，把每一个指向同一个人的索引名下的所有邮箱地址都归入这些索引共同的祖先，也就是将这些邮箱地址归入这些索引共同指向的那一个人名下，这样，就可以完成初步的合并，最后对于每一个人的邮箱地址排序即可
        int n = accounts.size();
        unordered_map<string, int> mail_id;
        // 创建一个字典，用邮箱地址当键，用地址所属的索引当值，这样在同一个邮箱地址同属于两个索引的时候就可以更加方便地判断
        QuickUnionFindSet Q(n);
        for (int i=0; i<n; i++){
            int m = accounts[i].size();
            for (int j=1; j<m; j++){
                string tmp_mail = accounts[i][j];
                if (mail_id.count(tmp_mail)){
                    // 如果之前该邮箱地址已经属于另一个人，结果现在又属于索引i的这个人，就可以发现这两个索引其实是一个人，这样直接对两个索引合并即可
                    Q.Union(i, mail_id[tmp_mail]);
                }
                else{
                    // 如果这是第一次遇到该邮箱，就直接存储
                    mail_id[tmp_mail] = i;
                }
            }
        }

        // 上面的操作已经可以将可以合并的索引都指向同一个人了，接下来只需要进行反向操作即可
        // 利用并查集快速找出每一个索引指向的那个人，并将邮箱地址直接归入那个人即可
        unordered_map<int, vector<string>> id_mail;
        for (auto &[mail, id] : mail_id){
            int tmp_root = Q.FindRoot(id); // 找指向的人
            id_mail[tmp_root].push_back(mail); // 合并邮箱
        }

        // 最后只需要依照题目的意思进行排序即可
        vector<vector<string>> res;
        for (auto &[id, mail] : id_mail){
            sort(mail.begin(), mail.end());
            mail.insert(mail.begin(), accounts[id][0]);
            res.push_back(mail);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<vector<string>> res = s.accountsMerge(accounts);
    for (auto i : res){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
