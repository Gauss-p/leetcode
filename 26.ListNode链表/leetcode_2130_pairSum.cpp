#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while (tmp){
            n++;
            tmp = tmp->next;
        }

        n /= 2;
        int pos = n;
        ListNode* cur2 = head;
        while (pos){
            cur2 = cur2->next;
            pos--;
        }

        vector<int> res(n);
        ListNode* cur1 = head;
        int indx = 0;
        while (cur2){
            res[indx] += cur1->val;
            res[n-indx-1] += cur2->val;
            cur1 = cur1->next;
            cur2 = cur2->next;
            indx++;
        }
        return *max_element(res.begin(), res.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,4,2,1};
    ListNode* ln = new ListNode();
    ListNode* head = ln;
    for (int i : nums){
        ListNode* cur = new ListNode(i);
        ln->next = cur;
        ln = ln->next;
    }
    cout << s.pairSum(head->next) << endl;
}
