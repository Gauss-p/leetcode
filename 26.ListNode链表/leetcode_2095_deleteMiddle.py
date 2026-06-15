from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head
        while fast.next and fast.next.next:
            fast = fast.next.next
            if fast.next:
                slow = slow.next
        if slow.next:
            slow.next = slow.next.next
            return head
        return head.next

if __name__ == "__main__":
    s = Solution()
    nums = [1,3,4,7,1,2,6]
    ln = ListNode()
    head = ln
    for i in nums:
        ln.next = ListNode(i)
        ln = ln.next
    res = s.deleteMiddle(head.next)
    while res:
        print(res.val, end = " ")
        res = res.next
    print()
