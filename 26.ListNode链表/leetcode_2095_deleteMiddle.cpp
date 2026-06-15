#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next){
            fast = fast->next->next;
            if (fast->next){
                slow = slow->next;
            }
        }
        if (slow->next){
            slow->next = slow->next->next;
            return head;
        }
        return head->next;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,4,7,1,2,6};
    ListNode* ln = new ListNode();
    ListNode* head = ln;
    for (int i : nums){
        ListNode* cur = new ListNode(i);
        ln->next = cur;
        ln = ln->next;
    }
    ListNode* res = s.deleteMiddle(head->next);
    while (res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}
