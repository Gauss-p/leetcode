from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 将链表首尾相连，然后循环移动找断开点即可
        if not head:
            return head
        cur = head
        n = 1
        while cur.next:
            n += 1
            cur = cur.next

        cur.next = head
        k %= n
        target = n-k-1
        for _ in range(target):
            head = head.next
        
        res = head.next
        head.next = None
        return res

if __name__ == "__main__":
    s = Solution()
    lst = [1,2,3,4,5]
    ln = ListNode()
    head = ln
    for i in lst:
        newNode = ListNode(i)
        ln.next = newNode
        ln = ln.next
    head = head.next
    
    k = 2
    res = s.rotateRight(head, k)
    while res:
        print(res.val, end = " ")
        res = res.next
    print()
