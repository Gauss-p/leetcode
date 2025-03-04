class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n == 1:
            return ""
        # 如果所有字符(总数是奇数时中间除外)都是a，那么将最后一个字符变成b即可
        # 否则在循环过程中只要遇到不是a就将其变成a返回
        for i in range(n//2):
            if palindrome[i]!='a':
                return palindrome[:i]+'a'+palindrome[i+1:]
        return palindrome[:n-1]+'b'

if __name__ == "__main__":
    s = Solution()
    palindrome = "abccba"
    print(s.breakPalindrome(palindrome))
