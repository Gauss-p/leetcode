class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        left = ''.join(sorted(s[:n//2]))
        return left+(s[n//2] if n%2 else "")+left[::-1]

if __name__ == "__main__":
    sl = Solution()
    s = "baab"
    print(sl.smallestPalindrome(s))
