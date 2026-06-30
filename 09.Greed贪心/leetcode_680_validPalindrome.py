class Solution:
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        def myCheck(op):
            i, j = 0, n-1
            tmp = 0
            while i<j:
                if s[i]!=s[j]:
                    if tmp==1: return False
                    tmp = 1
                    if op==0:
                        i += 1
                    else:
                        j -= 1
                else:
                    i += 1
                    j -= 1
            return True
        return myCheck(0) | myCheck(1)

if __name__ == "__main__":
    sl = Solution()
    s = "abc"
    print(sl.validPalindrome(s))
