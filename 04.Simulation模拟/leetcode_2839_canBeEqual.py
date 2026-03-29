class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return (s1[0]+s1[2] in [s2[0]+s2[2], s2[2]+s2[0]]) and (s1[1]+s1[3] in [s2[1]+s2[3], s2[3]+s2[1]])

if __name__ == "__main__":
    s = Solution()
    s1, s2 = "abcd", "cdab"
    print(s.canBeEqual(s1, s2))
