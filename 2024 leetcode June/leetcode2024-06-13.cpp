#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        // ����ǰk����������ֱ�ӽ��д�����ż���һ��������
        // ͬʱ���ڳ����ظ��ı�ţ����Խ�����ļ���"��ɾ���б�"profit
        // ��������Ϊk�Ժ���б����ж��Ƿ������profit�е������滻�������滻��Ҫ��������������
        // 1����ǰ�б�ı����֮ǰû�г��ֹ�
        // 2����ǰk���б����п����滻���б�(�����ظ���ŵ��б�)
        // ��������Ԫ�ض����������ж��Լ��������Ϳ����������Ŷ�
        long long res = 0, sum = 0;
        vector<int> profit;
        set<int> cg;
        sort(items.begin(), items.end(), greater<vector<int>>());
        for (int i=0; i<k; i++){
            if (cg.count(items[i][1])){
                profit.push_back(items[i][0]);
            }
            else{
                cg.insert(items[i][1]);
            }
            sum += items[i][0];
        }
        res = sum + 1ll*cg.size()*cg.size();
        int n = items.size();
        for (int i=k; i<n; i++){
            if (cg.count(items[i][1])) continue;
            if (profit.size() != 0){
                cg.insert(items[i][1]);
                sum -= profit.back();
                sum += items[i][0];
                long long tmp = sum + 1ll*cg.size()*cg.size();
                res = max(res, tmp);
                profit.pop_back();
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> items = {{3,2},{5,1},{10,1}};
    int k = 2;
    cout << s.findMaximumElegance(items, k) << endl;
}
