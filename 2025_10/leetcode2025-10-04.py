from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 用双指针的思路，定义l,r分别表示容器的两个边，初始值就应当为0和n-1。那么如果某一个时刻l对应的边小于r对应的边了，接下来应当怎么移动两边界呢？贪心地想，肯定是将l向右移动更好，因为如果这样移动，还有可能碰到比height[l]更大的边界，但如果单单移动r，就算遇到更大的边界，l对应的小边界依然限制了容器的容量大小
        # 反之亦然，如果某一时刻r对应的边界小于l对应的边了，就应当移动r，这样的过程一直进行到l=r为止即可，每一次求出容积取最大值即为答案
        n = len(height)
        l, r = 0, n-1
        res = 0
        while l<r:
            if height[l] < height[r]:
                res = max(res, (r-l)*height[l])
                l += 1
            else:
                res = max(res, (r-l)*height[r])
                r -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    height = [1,8,6,2,5,4,8,3,7]
    print(s.maxArea(height))
