class Solution:
    def minimumCost(self, s: str) -> int:
        # 将字符串s按照1和0分组，例如对于"0011001"，我们将其分为["00","11","00","1"]，但是为了方便计算翻转的代价，我们将其按照索引存储，即存储为[[0,2],[2,4],[4,6],[6,7]]
        # 然后对于分出来的任意一个组，我们只需对其左右两边的组进行翻转即可。对于上面索引为1的组[2,4]，往左边一共需要翻转一个组，代价为2，而往右边一共需要翻转两个组，我们需要求后缀和，按照题目给出的翻转后缀的代价计算公式，即(7-4)+(7-6)=4，这时我们计算出的总代价为2+4=6
        # 因为要多次求总代价，所以我们求出代价的前缀和以及代价的后缀和，对于每一个组计算即可
        # 又因为我们需要将其分组，所以在字符串最后加一个哨兵，方便一次循环就存储全
        s += "2"
        n = len(s)
        groups = []
        last = 0
        for i in range(1,n):
            # 进行分组
            if s[i] != s[last]:
                groups.append([last, i])
                last = i
        
        m = len(groups)
        pre, aft = [0]*(m+1), [0]*(m+1)
        for i in range(m):
            # 计算代价前缀后缀和
            pre[i+1] = pre[i] + groups[i][1]
            aft[m-i-1] = aft[m-i] + (n-1-groups[m-i-1][0])
        
        res = float("inf")
        for i in range(m):
            # 计算总代价的最小值
            res = min(res, pre[i]+aft[i+1])
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "0011"
    print(sl.minimumCost(s))
