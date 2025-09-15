class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        for i in brokenLetters:
            text = text.replace(i, "*")
        return sum("*" not in w for w in text.split())

if __name__ == "__main__":
    s = Solution()
    text = "hello world"
    brokenLetters = "ad"
    print(s.canBeTypedWords(text, brokenLetters))
