#include <iostream>
#include <vector>
#include <climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 0;
        int lastPos = -1, mn = INT_MAX, first = -1, last = -1, lastVal = 0;
        while (head){
            int cur = head->val;
            if (pos > 0 && head->next){
                if ((cur > lastVal && cur > head->next->val) || (cur < lastVal && cur < head->next->val)){
                    if (lastPos >= 0){
                        mn = min(mn, pos-lastPos);
                    }
                    if (first == -1){
                        first = pos;
                    }
                    last = pos;
                    lastPos = pos;
                }
            }
            lastVal = cur;
            pos++;
            head = head->next;
        }
        if (mn == INT_MAX){
            return {-1,-1};
        }
        return {mn, last-first};
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,3,1,2,5,1,2};
    ListNode* ln = new ListNode();
    ListNode* head = ln;
    for (int i : nums){
        ListNode* nxt = new ListNode(i);
        ln->next = nxt;
        ln = ln->next;
    }
    vector<int> res = s.nodesBetweenCriticalPoints(head->next);
    cout << res[0] << " " << res[1] << endl;
}
