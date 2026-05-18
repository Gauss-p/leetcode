class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        diff = [0]*26
        for s in word2:
            diff[ord(s)-ord('a')] -= 1
        cnt = sum(1 for c in diff if c<0)

        def update(c, op):
            nonlocal cnt
            tmpIndx = ord(c)-ord('a')
            diff[tmpIndx] += op
            if op==1 and diff[tmpIndx]==0:
                cnt -= 1
            elif op==-1 and diff[tmpIndx]==-1:
                cnt += 1

        n = len(word1)
        l,r = 0,0
        res = 0
        while l<n:
            while r<n and cnt>0:
                update(word1[r], 1)
                r += 1
            if cnt == 0:
                res += n-r+1
            update(word1[l], -1)
            l += 1
        return res

if __name__ == "__main__":
    s = Solution()
    word1 = "bcca"
    word2 = "abc"
    print(s.validSubstringCount(word1,word2))
