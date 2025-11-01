#include <iostream>
#include <vector>
#include <unordered_set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* ln = new ListNode(0, head);
        ListNode* res = ln;
        while (ln->next){
            ListNode* nxt = ln->next;
            if (st.count(nxt->val)){
                ln->next = nxt->next;
            }
            else{
                ln = nxt;
            }
        }
        return res->next;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<int> hNum = {1,2,3,4,5};
    ListNode* hLn = new ListNode();
    ListNode* head = hLn;
    for (auto& i : hNum){
        ListNode* nxt = new ListNode(i);
        hLn->next = nxt;
        hLn = hLn->next;
    }
    head = head->next;

    ListNode* res = s.modifiedList(nums, head);
    while (res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}
