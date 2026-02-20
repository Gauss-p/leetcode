from typing import List

class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        # 遍历所有长度为2*k的子数组分别判断
        n = len(nums)
        cur = []
        for i in range(n):
            cur.append(nums[i])
            if i<2*k-1:
                continue
            flag = True
            for j in range(1, 2*k):
                if j!=k and cur[j-1]>=cur[j]:
                    flag = False
                    break
            if flag:
                return True
            cur.pop(0)
        return False

if __name__ == "__main__":
    s = Solution()
    nums = [2,5,7,8,9,2,3,4,3,1]
    k = 3
    print(s.hasIncreasingSubarrays(nums, k))
