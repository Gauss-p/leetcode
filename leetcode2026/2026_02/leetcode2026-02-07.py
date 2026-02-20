class Solution:
    def minimumDeletions(self, s: str) -> int:
        myMin = lambda x,y : x if x<y else y
        res = s.count('a') # 初始化为「不保留任何a」的情况
        cnt = 0 # 在循环时维护小于等于当前位置的b的数量
        totA = res # 在循环时维护大于当前位置的a的数量
        for i in s:
            if i == 'b':
                cnt += 1
            if i == 'a':
                totA -= 1
            res = myMin(res, cnt+totA) # 删除当前位置左侧所有b和右侧所有a，才能实现平衡
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "aababbab"
    print(sl.minimumDeletions(s))
