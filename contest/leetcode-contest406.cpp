#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for (int i=0; i<n-1; i++){
            int a = s[i]-'0', b = s[i+1]-'0';
            if (a%2 == b%2 && a > b){
                swap(s[i], s[i+1]);
                break;
            }
        }
        return s;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> setNums(nums.begin(), nums.end());
        ListNode* res = new ListNode();
        ListNode* Reshead = res;
        while (head){
            if (setNums.count(head->val) == 0){
                ListNode* tmp = new ListNode(head->val);
                res->next = tmp;
                res = res->next;
            }
            head = head->next;
        }
        return Reshead->next;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // ���������Ŀ��˼·�������ģ���Ϊ�������Խ��������Ҫ������ʹ�õĴ��������ܵ��٣����������ǾͿ��Խ����������б��������ͬʱҪ��¼����������ܹ��е���Ŀ
        // ���ѭ�������б�����������ָ��ֱ�ѭ�������б���һ���������һ�������������Ҫ�Ĵ��۸��󣬾������У�Ȼ�󽫺����г��Ŀ�����һ����ʱ�𰸾�һ����Ҫ�����е�ǰ�еĴ��۳��������г��Ŀ���
        // ��֮���������Ĵ��۸��󣬾����������ٽ������г��Ŀ�����һ
        // ��Ϊ�п�������������֮һû��ѭ�����ʱ���ѭ���ͽ����ˣ��������Ǽ�����Сѭ�����ֱ��������ļ�������
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int i=0, j=0;
        int vert = 1, hori = 1;
        int res = 0;
        while (i < m-1 && j < n-1){
            if (horizontalCut[i] > verticalCut[j]){
                res += horizontalCut[i]*vert;
                hori++;
                i++;
            }
            else{
                res += verticalCut[j]*hori;
                vert++;
                j++;
            }
        }
        while (i < m-1){
            res += horizontalCut[i]*vert;
            i++;
        }
        while (j < n-1){
            res += verticalCut[j]*hori;
            j++;
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "42530";
    cout << s.getSmallestString(str) << endl;
    // -----------------------------------------------------------------
    vector<int> nums = {1,2,3};
    ListNode* ln;
    ListNode* head = ln;
    vector<int> test = {1,2,3,4,5};
    for (auto i : test){
        ListNode* tmp = new ListNode(i);
        ln->next = tmp;
        ln = ln->next;
    }
    ListNode* res = s.modifiedList(nums, head);
    res = res->next;
    while (res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    // -----------------------------------------------------------------
    int m = 3, n = 2;
    vector<int> horizontalCut = {1, 3}, verticalCut = {5};
    cout << s.minimumCost(m, n, horizontalCut, verticalCut) << endl;
}
