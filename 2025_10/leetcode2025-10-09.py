from typing import List

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        # 定义last数组，表示每一个巫师上一次结束工作的时间，那么为了让每一个巫师都能够顺利进行下一次工作，我们需要计算每一轮新的药水加工的最终结束时间，然后倒推出来所有巫师开始工作的时间，在计算结束时间的时候，就需要和当前巫师的上一次工作结束时间求一次最大值，以防这个巫师还在工作的时候又给他一个药水让他加工
        m, n = len(mana), len(skill)
        last = [0]*n
        for i in range(m):
            time = 0
            for j in range(n):
                if time < last[j]:
                    time = last[j] # 避免时间上的重叠
                time += skill[j]*mana[i]
            
            last[-1] = time
            for j in range(n-2, -1, -1):
                # 依据最后结束时间还原每一个人的结束时间
                last[j] = last[j+1]-skill[j+1]*mana[i]
        return last[-1]

if __name__ == "__main__":
    s = Solution()
    skill = [1,5,2,4]
    mana = [5,1,4,2]
    print(s.minTime(skill, mana))
