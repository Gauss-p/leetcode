from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # 将nums按照连续1和连续非1进行分组，并将交界处的左侧索引加入一个列表中，为了方便之后计算，我们可以在nums的前后分别加入哨兵，以防nums开头即为1和nums结尾是1的情况。这样，在索引列表中从头开始循环，每四个索引为一组，每两组之间间隔为2，那么这四个索引就对应了：一组连续1，一组连续非1，一组连续1，只要中将一组的长度为1，就可以将前后两组长度之和计入答案
        # 但是我们还需要计算nums中本身的最长连续1的个数，为了防止nums中只有一组连续1的情况，同时，如果nums中有0，我们就可以将最长连续1全选，否则只能选它的长度减1
        nums.append(0)
        nums.insert(0, 0)
        n = len(nums)
        flag = (0 in nums[1:n-1])
        pos = []
        res = 0
        oneCnt = 0
        for i in range(n):
            # 求最长连续1的个数
            if nums[i] == 1:
                oneCnt += 1
            else:
                if flag:
                    res = max(res, oneCnt)
                else:
                    res = max(res, oneCnt-1)
                oneCnt = 0

        for i in range(n-1):
            # 加入间隔索引
            if nums[i] == 1 and nums[i+1] != 1:
                pos.append(i)
            if nums[i] != 1 and nums[i+1] == 1:
                pos.append(i)
                
        for i in range(0, len(pos), 2):
            # 四个四个索引循环
            if i+4>len(pos):
                break
            a, b, c, d = pos[i:i+4]
            if c-b==1:
                res = max(res, b-a+d-c)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,0,1]
    print(s.longestSubarray(nums))
