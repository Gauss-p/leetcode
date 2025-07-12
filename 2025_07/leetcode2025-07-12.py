from typing import List
from functools import cache

class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        # 注意，为了方便叙述，接下来的"位次"均为从1开始编号的，并非"索引"
        # 我们定义一个函数F(n, f, s)，返回值是：n名运动员，两个最佳运动员的位次分别是f和s，这两个运动员最早相遇的回合数是多少。对应的，我们定义一个函数G(n, f, s)就表示在同样的条件下，两个运动员最晚相遇的回合数是多少
        # 首先考虑他们相遇的情况，当且仅当两者在列表中的位次正好关于列表的中间点对称时才可以让两者相遇，所以，那么当(f+s)//2=n//2时，也就是f+s=n时，就说明这两名运动员正好处在对称的位置，这时候直接返回1即可，因为他们在当前回合一定会遇到的，这个就可以作为函数F的递归基
        # 接下来考虑两者位置的不同组合情况，为了方便计算，我们尽可能地在F中传入的运动员的位置保证f<s，这就需要我们对于两者的位次进行等价变换。对于两个运动员，每一个运动员都有可能位于整个列表的左侧、中间、或者右侧，因此两者位置的组合就有9种情况，但是由于他们不可能同时位于中间位置，因此总共只有8种情况。
        # 然后我们考虑等价变换的方式，首先，如果交换两个最佳运动员的位置，对答案是没有影响的，因为哪个放在第一个数字都没关系，也就是说，他们的位次(f, s)就可以等同为(s, f)；其次，如果整个列表同时翻转，对答案是没有影响的，因为每一次都是对于所有关于列表中点对称的所有数对进行操作，所以整个数组对称后对于所有对称数对是没有影响的，因此，最佳运动员的位次(f, s)就可以等同为(n+1-f, n+1-s)，在利用上面的等价变换方式，可以发现(f, s)等同于(n+1-s, n+1-f)
        # 利用上面的两个式子，我们可以将8种情况全部转换成以下三种情况：f位于左边一半，s位于1:左边一半,2:中间位置,或3:右边一半。
        # 对于第1,2种情况，可以发现位于[1,f-1]的所有普通运动员都是和对面的普通运动员对抗的，且位于[f+1, s-1]的所有普通运动员也都是和对面的普通运动员对抗的，剩余中间没有考虑到的位置也都是普通对抗普通，因此我们假设[1,f-1]中剩下了i个人，[f+1,s-1]中剩下了j个人，那么下一轮中，f的位置就应该是i+1，s的位置就应该是i+j+2，并且总共剩余的人数应该是(n+1)//2，因此接下来递归的数据就应该是F((n+1)//2, i+1, i+j+2)，递归出来后取最小值，并加上当前回合的1，即可求出当前情况下的答案
        # 对于第3种情况，可以发现和s对抗的是关于中间值对称的s'位置的普通运动员，因此s'一定会在当前回合牺牲，接下来考虑f和s'的位置关系，分为两种：1.f<s'；2.f>s'
        # 对于第1种情况，可以发现[1,f-1]中所有的普通运动员和[f+1,s'-1]中的所有普通运动员都是和对面的普通运动员对抗的，因此他们剩余的人数可以随意由我们控制，s'一定会牺牲，就不计他了，然后对于[s'+1, s-1]中的所有运动员一定会剩下一半的人，也就是((s-s'-1)+1)//2，即(s-s')//2，因此假设[1,f-1]中剩余i个人，[f+1,s'-1]中剩余j个人，那么下一轮中f对应的位置就应该是i+1，s对应的位置就应该是i+j+2+(s-s')//2，因此下一次传入的就应该是F((n+1)//2, i+1, i+j+2+(s-s')//2)
        # 对于第2种情况，我们可以先将f和s变换成n+1-s和n+1-f，这样就可以保证newF<newS，并且此时的newS'=n+1-newS=f，且f>s'=n+1-s，因此此时newF=n+1-s<newS'，这样就可以将newF,newS和newS'按照上面的方式处理即可
        # 最晚回合也用同样的方式计算即可
        @cache
        def dfs(n, f, s):
            if f+s == n+1:
                # 递归基
                return (1,1)
            
            if f+s > n+1:
                # 防止s<f
                return dfs(n, n+1-s, n+1-f)

            earliest, latest = float("inf"), -float("inf") # 保存当前的最早和最晚回合
            mid = (n+1)//2 # 当前的中间点
            if s <= mid:
                # 第1,2种情况，遍历所有可能的i和j
                for i in range(f):
                    for j in range(s-f):
                        # 更新当前最大和最小回合数
                        curE, curL = dfs(mid, i+1, i+j+2)
                        earliest = min(earliest, curE)
                        latest = max(latest, curL)
            else:
                s_prime = n+1-s # 计算出当前的s'
                ssMid = (n-2*s_prime+1)//2 # 计算出下一轮的s'和s中间会剩余的人数
                # 遍历所有可能的i和j
                for i in range(f):
                    for j in range(s_prime-f):
                        # 更新当前最早和最晚回合数
                        curE, curL = dfs(mid, i+1, i+j+ssMid+2)
                        earliest = min(earliest, curE)
                        latest = max(latest, curL)
            
            # 注意加上当前一个回合
            return (earliest+1, latest+1)

        if firstPlayer > secondPlayer:
            # 保证第一次传入的是f<s
            firstPlayer, secondPlayer = secondPlayer, firstPlayer
        resE, resL = dfs(n, firstPlayer, secondPlayer) # 求出答案
        return [resE, resL]

if __name__ == "__main__":
    s = Solution()
    n = 11
    firstPlayer, secondPlayer = 2, 4
    print(s.earliestAndLatest(n, firstPlayer, secondPlayer))
