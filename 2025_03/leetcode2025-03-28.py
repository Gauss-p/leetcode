class Solution:
    def minimizedStringLength(self, s: str) -> int:
        return len(set(s))

if __name__ == "__main__":
    sl = Solution()
    s = "aaabc"
    print(sl.minimizedStringLength(s))
