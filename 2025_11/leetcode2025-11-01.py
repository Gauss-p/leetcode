from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        ln = ListNode()
        res = ln
        st = set(nums)
        while head:
            if head.val not in st:
                ln.next = ListNode(head.val)
                ln = ln.next
            head = head.next
        return res.next

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    hNum = [1,2,3,4,5]
    hLn = ListNode()
    head = hLn
    for i in hNum:
        hLn.next = ListNode(i)
        hLn = hLn.next
    head = head.next

    res = s.modifiedList(nums, head)
    while res:
        print(res.val)
        res = res.next
