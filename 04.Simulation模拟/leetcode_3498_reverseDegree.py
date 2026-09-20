class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum((ord('z')-ord(c)+1)*(i+1) for i,c in enumerate(s))

if __name__ == "__main__":
    sl = Solution()
    s = "abc"
    print(sl.reverseDegree(s))
