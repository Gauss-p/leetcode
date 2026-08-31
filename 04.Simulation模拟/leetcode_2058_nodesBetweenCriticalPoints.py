from typing import List,Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        pos = 0
        lastPos = -1
        mn = 10**18
        first, final = -1, -1
        lastVal = 0
        while head:
            cur = head.val
            if pos > 0 and head.next:
                if (cur > lastVal and cur > head.next.val) or (cur < lastVal and cur < head.next.val):
                    if lastPos >= 0:
                        mn = min(mn, pos-lastPos)
                    if first == -1:
                        first = pos
                    final = pos
                    lastPos = pos
            lastVal = cur
            pos += 1
            head = head.next
        return [mn, final-first] if mn != 10**18 else [-1,-1]

if __name__ == "__main__":
    s = Solution()
    nums = [5,3,1,2,5,1,2]
    ln = ListNode()
    head = ln
    for i in nums:
        ln.next = ListNode(i)
        ln = ln.next
    print(s.nodesBetweenCriticalPoints(head.next))
