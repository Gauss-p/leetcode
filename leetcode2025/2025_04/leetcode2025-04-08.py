from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        st = set()
        indx = -1
        for i in range(n-1, -1, -1):
            if nums[i] in st:
                indx = i
                break
            st.add(nums[i])
        return (indx+3)//3

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,2,3,3,5,7]
    print(s.minimumOperations(nums))
