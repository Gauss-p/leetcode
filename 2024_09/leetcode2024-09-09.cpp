#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ln = new ListNode();
        ListNode* hd = ln;
        int tmp = 0;
        head = head->next;
        while (head){
            if (head->val == 0){
                ListNode* tmp_ln = new ListNode(tmp);
                ln->next = tmp_ln;
                ln = ln->next;
                tmp = 0;
            }
            else{
                tmp += head->val;
            }
            head = head->next;
        }
        return hd->next;
    }
};

int main(){
    ListNode* l = new ListNode(0);
    ListNode* head = l;
    vector<int> v = {1,0,3,0,2,2,0};
    for (auto i : v){
        ListNode* tmp_ln = new ListNode(i);
        l->next = tmp_ln;
        l = l->next;
    }
    Solution s;
    ListNode* res = s.mergeNodes(head);
    vector<int> vRes;
    while (res){
        vRes.push_back(res->val);
        res = res->next;
    }
    for (auto i : vRes){
        cout << i << " ";
    }
    cout << endl;
}

