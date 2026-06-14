from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        n = 0
        tmp = head
        while tmp:
            n += 1
            tmp = tmp.next
        
        n //= 2
        cur2 = head
        pos = n
        while pos:
            cur2 = cur2.next
            pos -= 1
        
        cur1 = head
        res = [0]*n
        indx = 0
        while cur2:
            res[indx] += cur1.val
            res[n-indx-1] += cur2.val
            cur1 = cur1.next
            cur2 = cur2.next
            indx += 1
        return max(res)

if __name__ == "__main__":
    s = Solution()
    nums = [5,4,2,1]
    ln = ListNode()
    head = ln
    for i in nums:
        ln.next = ListNode(i)
        ln = ln.next
    print(s.pairSum(head.next))
