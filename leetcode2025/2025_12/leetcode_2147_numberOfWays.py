class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # 在所有的座位中，我们可以在总第偶数个座位之后和其下一个座位之前放一个屏风，因此我们只需要将所有的「第偶数个座位和其下一个座位之间的距离」相乘即可得到答案
        tot = 0
        last = -1
        res = 1
        modNum = 1_000_000_007
        for i in range(len(corridor)):
            c = corridor[i]
            if c == 'S':
                tot += 1
                if tot > 1 and tot&1:
                    res = res*(i-last)%modNum
                last = i
        return res if tot%2==0 and tot>=2 else 0

if __name__ == "__main__":
    s = Solution()
    corridor = "SSPPSPS"
    print(s.numberOfWays(corridor))
