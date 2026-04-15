from typing import List

class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        for i in range(n//2+1):
            if words[(startIndex-i)%n]==target or words[(startIndex+i)%n]==target:
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    words = ["hello","i","am","leetcode","hello"]
    target = "hello"
    startIndex = 1
    print(s.closestTarget(words, target, startIndex))
