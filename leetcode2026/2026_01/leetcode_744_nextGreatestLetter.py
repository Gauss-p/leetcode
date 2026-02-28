from typing import List

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        l, r = 0, n-1
        while l<=r:
            mid = (l+r)//2
            if letters[mid] > target:
                r = mid-1
            else:
                l = mid+1
        return letters[l%n]

if __name__ == "__main__":
    s = Solution()
    letters = ["c","f","j"]
    target = "a"
    print(s.nextGreatestLetter(letters, target))
