class Solution:
    def maximum69Number(self, num: int) -> int:
        s = str(num)
        for i in range(len(s)):
            if s[i] == '6':
                s = s[:i]+'9'+s[i+1:]
                return int(s)
        return num

if __name__ == "__main__":
    s = Solution()
    num = 9669
    print(s.maximum69Number(num))
