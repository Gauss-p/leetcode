from typing import List
from collections import deque

class Node:
    def __init__(self, length=0):
        self.son = [None]*26
        self.fail = None
        self.length = length

class AhoCorasick:
    def __init__(self):
        self.root = Node()
    
    def put(self, w):
        cur = self.root
        for s in w:
            s = ord(s)-ord('a')
            if cur.son[s] is None:
                cur.son[s] = Node(cur.length+1)
            cur = cur.son[s]

    def build_fail(self):
        self.root.fail = self.root

        q = deque()
        for i,son in enumerate(self.root.son):
            if son is None:
                self.root.son[i] = self.root
            else:
                son.fail = self.root
                q.append(son)

        while q:
            cur = q.popleft()
            for i, son in enumerate(cur.son):
                if son is None:
                    cur.son[i] = cur.fail.son[i]
                    continue
                son.fail = cur.fail.son[i]
                q.append(son)

class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        ac = AhoCorasick()
        for w in words:
            ac.put(w)
        ac.build_fail()

        n = len(target)
        f = [0]*(n+1)
        cur = root = ac.root
        for i,s in enumerate(target, 1):
            cur = cur.son[ord(s)-ord('a')]
            if cur is root:
                return -1
            f[i] = f[i-cur.length]+1
        return f[n]

if __name__ == "__main__":
    s = Solution()
    words = ["abc","aaaaa","bcdef"]
    target = "aabcdabc"
    print(s.minValidStrings(words, target))
