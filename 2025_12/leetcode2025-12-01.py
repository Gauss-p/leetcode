from typing import List

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        # 用二分查找的思路，如果给定一个最长时间mid，我们如何判断能否达到这个最长时间呢？对于每一个电池，如果它的容量是b，而我们使用的最长时间是mid，在最终使用完的时候，如果b<mid，那么这个电池最大的使用量就是b，即将它全部用完，如果b>mid，那么这个电池最大使用量就是mid，不需要将它全部用完，只需用这一个电池从头到尾供给一个电脑即可。通过这种方式，我们就可以求得所有电池能够贡献出的总电量tot，如果每个电脑都需要使用mid时长，那么总需求电量就是n*mid。最后，只有tot大于等于n*mid时，才说明所有电脑同时运行mid时长是可行的
        def check(mid):
            tot = 0
            for i in batteries:
                if mid<i:
                    tot += mid
                else:
                    tot += i
            return tot >= n*mid
        
        l, r = 0, sum(batteries)//n
        while l<=r:
            mid = (l+r)//2
            if check(mid):
                l = mid+1
            else:
                r = mid-1
        return r

if __name__ == "__main__":
    s = Solution()
    n = 2
    batteries = [3,3,3]
    print(s.maxRunTime(n, batteries))
