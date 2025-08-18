from typing import List

class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        # 用dfs的方式，暴力遍历所有情况，依次判断是否能够组成24即可
        # 每一次在给出的nums中选出两个数字，对这两个数字进行优先运算，然后再加入列表中，继续传入dfs函数进行选取并计算，一直到nums中只剩下一个数字时，判断该数字是否非常接近24即可(这是因为除法运算可能出现小数)
        # 接下来，对于选出的两个数字x和y，我们有以下六种运算：x+y, x-y, y-x, x*y, x/y(y!=0), y/x(x!=0)，因此只需对选出的两个数字进行这六种运算分别继续传入函数中即可
        def dfs(nums):
            if len(nums) == 1:
                return abs(nums[0]-24) <= 1e-9

            ans = False
            for i in range(len(nums)):
                for j in range(i+1, len(nums)):
                    cur = nums.copy()
                    cur.pop(j)
                    cur.pop(i)
                    ans = ans or dfs(cur+[nums[i]+nums[j]])
                    ans = ans or dfs(cur+[nums[i]-nums[j]])
                    ans = ans or dfs(cur+[nums[j]-nums[i]])
                    ans = ans or dfs(cur+[nums[i]*nums[j]])
                    if nums[j] != 0:
                        ans = ans or dfs(cur+[nums[i]/nums[j]])
                    if nums[i] != 0:
                        ans = ans or dfs(cur+[nums[j]/nums[i]])

                    if ans:
                        return True
            return False
        return dfs(cards)

if __name__ == "__main__":
    s = Solution()
    cards = [4,1,8,7]
    print(s.judgePoint24(cards));
