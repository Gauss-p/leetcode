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
    // �������鼯��ʵֻ��Ҫһ���б�����ˣ�����ÿһ������ָ�������ϴ�Ҳ�����������������������Ϳ��Խ�ÿһ�����Ͽ��������еĲ���Ԫ����ɵ���ͨ����
    // ���鼯��Ҫʵ���������������Ҹ��ڵ㣬�ж�����Ԫ���Ƿ�����ͬһ�����ϣ��Լ��ϲ�����Ԫ�����ڵļ���
    // ���ڵ�һ�����������ǿ��ԶԴ�����������ϵ�����׷˷��һֱ���������ϵ���ˣ����ҵ��˵�ǰ�����������ϵĸ��ڵ㣬�������ǿ��Խ����Ż���Ҳ����ÿһ�ζ����ü��������е�Ԫ��ֱ��ָ����˵ĸ��ڵ㣬�����͸����
    // ���ڵڶ���������ֱ���ж������ڵ��������ϵĸ��ڵ��Ƿ���ͬ����
    // ���ڵ�����������ֱ�ӽ���һ�������ĸ��ڵ�ָ��ڶ��������ĸ��ڵ�Ϳ���ʵ����������֮��ĺϲ���
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
        // �������Ƕ���һ�����鼯���࣬�������������Ŀת��Ϊ�����ò��鼯��������
        // ���ò��鼯���Կ��ٺϲ���Ԫ�����ڼ��ϵ����ԣ����ǿ��Խ�ԭ�б��еĸ������������������棬Ȼ���������������ͬ��������Ӧ��һ����ͬ�������ַ����ֱ�Ӻϲ�����������������ָ��һ���˼���
        // ����������Ԫ�ؽ��в����Ժ󣬾ͻ��������಻ͬ����������ָ�����һ���ˣ�Ȼ�������ٷ����������ÿһ��ָ��ͬһ���˵��������µ����������ַ��������Щ������ͬ�����ȣ�Ҳ���ǽ���Щ�����ַ������Щ������ָͬ�����һ�������£��������Ϳ�����ɳ����ĺϲ���������ÿһ���˵������ַ���򼴿�
        int n = accounts.size();
        unordered_map<string, int> mail_id;
        // ����һ���ֵ䣬�������ַ�������õ�ַ������������ֵ��������ͬһ�������ַͬ��������������ʱ��Ϳ��Ը��ӷ�����ж�
        QuickUnionFindSet Q(n);
        for (int i=0; i<n; i++){
            int m = accounts[i].size();
            for (int j=1; j<m; j++){
                string tmp_mail = accounts[i][j];
                if (mail_id.count(tmp_mail)){
                    // ���֮ǰ�������ַ�Ѿ�������һ���ˣ������������������i������ˣ��Ϳ��Է���������������ʵ��һ���ˣ�����ֱ�Ӷ����������ϲ�����
                    Q.Union(i, mail_id[tmp_mail]);
                }
                else{
                    // ������ǵ�һ�����������䣬��ֱ�Ӵ洢
                    mail_id[tmp_mail] = i;
                }
            }
        }

        // ����Ĳ����Ѿ����Խ����Ժϲ���������ָ��ͬһ�����ˣ�������ֻ��Ҫ���з����������
        // ���ò��鼯�����ҳ�ÿһ������ָ����Ǹ��ˣ����������ֱַ�ӹ����Ǹ��˼���
        unordered_map<int, vector<string>> id_mail;
        for (auto &[mail, id] : mail_id){
            int tmp_root = Q.FindRoot(id); // ��ָ�����
            id_mail[tmp_root].push_back(mail); // �ϲ�����
        }

        // ���ֻ��Ҫ������Ŀ����˼�������򼴿�
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
