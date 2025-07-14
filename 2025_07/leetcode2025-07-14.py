from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        res = 0
        while head:
            res = res*2+head.val
            head = head.next
        return res

if __name__ == "__main__":
    s = Solution()
    ln = ListNode()
    head = ln
    vals = [1,0,1]
    for i in vals:
        nxt = ListNode(i)
        ln.next = nxt
        ln = ln.next
    head = head.next
    print(s.getDecimalValue(head))
