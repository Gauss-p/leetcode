from typing import List
from collections import defaultdict

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        def canBalanced(length):
            odd = defaultdict(int)
            even = defaultdict(int)
            for i in range(n):
                x = nums[i]
                if x&1: odd[x] += 1
                else: even[x] += 1
                
                if i<length-1:
                    continue
                if len(odd) == len(even):
                    return True

                last = nums[i-length+1]
                if last&1:
                    odd[last] -= 1
                    if odd[last] == 0: odd.pop(last)
                else:
                    even[last] -= 1
                    if even[last] == 0: even.pop(last)
            return False
        
        for l in range(n, 0, -1):
            if canBalanced(l):
                return l
        return 0

if __name__ == "__main__":
    s = Solution()
    nums = [2,5,4,3]
    print(s.longestBalanced(nums))
