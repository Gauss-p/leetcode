#include <iostream>
#include <vector>
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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head){
            res = res*2+head->val;
            head = head->next;
        }
        return res;
    }
};

int main(){
    ListNode* ln = new ListNode();
    ListNode* head = ln;
    vector<int> vals = {1,0,1};
    for (int i : vals){
	ListNode* nxt = new ListNode(i);
	ln->next = nxt;
	ln = ln->next;
    }
    head = head->next;
    Solution s;
    cout << s.getDecimalValue(head) << endl;
}
