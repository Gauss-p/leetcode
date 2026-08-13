from typing import List

class SegmentTree:
    def __init__(self, s):
        self._n = len(s)
        self._s = s
        self._tree = [None]*(2<<((self._n-1).bit_length()))
        self._build(1, 0, self._n-1)

    def maintain(self, node, l, m, r):
        aMx, aPre, aSuf = self._tree[node*2]
        bMx, bPre, bSuf = self._tree[node*2+1]
        isSame = (self._s[m] == self._s[m+1])
        cur = [0,0,0]
        cur[0] = max(aMx, bMx)
        if isSame:
            cur[0] = max(cur[0], aSuf+bPre)

        cur[1] = aPre
        if aPre == m-l+1 and isSame:
            cur[1] = aPre+bPre

        cur[2] = bSuf
        if bSuf == r-m and isSame:
            cur[2] = aSuf+bSuf
        self._tree[node] = tuple(cur)
        
    def _build(self, node, l, r):
        if l == r:
            self._tree[node] = (1,1,1)
            return
        m = (l+r)//2
        self._build(node*2, l, m)
        self._build(node*2+1, m+1, r)
        self.maintain(node, l, m, r)
    
    def _update(self, node, l, r, indx, val):
        if l == r:
            self._s[indx] = val
            return
        m = (l+r)//2
        if indx <= m:
            self._update(node*2, l, m, indx, val)
        else:
            self._update(node*2+1, m+1, r, indx, val)
        self.maintain(node, l, m, r)

    def update(self, i, v):
        self._update(1, 0, self._n-1, i, v)
    
    def myQuery(self):
        return self._tree[1][0]

class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        st = SegmentTree(list(s))
        res = []
        for i in range(len(queryCharacters)):
            indx, v = queryIndices[i], queryCharacters[i]
            st.update(indx, v)
            res.append(st.myQuery())
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "babacc"
    queryCharacters = "bcb"
    queryIndices = [1,3,3]
    print(sl.longestRepeating(s, queryCharacters, queryIndices))
