from collections import Counter

class Solution:
    def smallestSubsequence(self, s: str) -> str:
        n = len(s)
        tot = Counter(s)
        st = []
        for i in range(n):
            c = s[i]
            tot[c] -= 1
            if c in st:
                continue
            while len(st) and st[-1] > c and tot[st[-1]]:
                st.pop()
            st.append(c)
        return ''.join(st)

if __name__ == "__main__":
    sl = Solution()
    s = "bcabc"
    print(sl.smallestSubsequence(s))
