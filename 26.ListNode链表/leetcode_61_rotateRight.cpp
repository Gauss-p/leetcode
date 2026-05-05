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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head){
            return head;
        }
        ListNode* cur = head;
        int n = 1;
        while (cur->next){
            n++;
            cur = cur->next;
        }

        cur->next = head;
        k %= n;
        int target = n-k-1;
        for (int i=0; i<target; i++){
            head = head->next;
        }
        ListNode* res = head->next;
        head->next = NULL;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    ListNode* ln = new ListNode();
    ListNode* head = ln;
    for (int i : nums){
        ListNode* newNode = new ListNode(i);
        ln->next = newNode;
        ln = ln->next;
    }
    head = head->next;

    int k = 2;
    ListNode* res = s.rotateRight(head, k);
    while (res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}
