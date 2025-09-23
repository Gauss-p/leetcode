class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def myInt(s):
            ans = 0
            for i in s:
                ans = ans*10+int(i)
            return ans
        v1 = list(map(myInt, version1.split('.')))
        v2 = list(map(myInt, version2.split('.')))
        for i in range(max(len(v1), len(v2))):
            cur1 = 0
            if i < len(v1):
                cur1 = v1[i]
            cur2 = 0
            if i < len(v2):
                cur2 = v2[i]
            if cur1 < cur2:
                return -1
            if cur1 > cur2:
                return 1
        return 0

if __name__ == "__main__":
    s = Solution()
    version1 = "1.2"
    version2 = "1.10"
    print(s.compareVersion(version1, version2))
