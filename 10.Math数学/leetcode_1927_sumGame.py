class Solution:
    def sumGame(self, num: str) -> bool:
        # 如果总共的?数量是奇数，那么最后一个数字的选择权掌握在alice手中，这时无论前面的情况是相等还是不等，alice都可以做出可以让自己胜利的选择；
        # 如果总共的?数量是偶数，那么不能简单地直接判断，可以这样想：将每一个问号当作4.5，分别计算出左右两部分的总和，记为lSum和rSum，这时，可以分以下两种情况考虑：
        # 1.lSum=rSum，如果称alice和bob都选完一次为一轮，那么在每一轮中，假如alice将某一边的一个?选为x，那么如果此时同一侧有剩余问号，bob即可将同侧问号选为9-x，即可保持两侧总和依然保持lSum和rSum不变；如果此时另一侧有剩余问号，bob即可将另一侧一个问号选为x，即可保持lSum和rSum仍然相等。故，该情况一定bob胜利
        # 2.lSum!=rSum，此时alice一定可以通过选择数字使得自己胜利，故alice胜利
        n = len(num)
        left, right = num[:n//2], num[n//2:]
        l, r = left.count('?'), right.count('?')
        if (l+r)&1:
            return True
        
        ls = sum(4.5 if i=='?' else int(i) for i in left)
        rs = sum(4.5 if i=='?' else int(i) for i in right)
        if ls == rs:
            return False
        return True

if __name__ == "__main__":
    s = Solution()
    num = "25??"
    print(s.sumGame(num))
