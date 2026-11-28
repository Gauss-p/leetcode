from typing import List

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        myMax = lambda x,y : x if x>y else y
        myMin = lambda x,y : x if x<y else y
        # 根据定义，differences是一个差分数组，那么我们只需还原数组，求出原数组中的最大值mx和最小值mn，因为没有固定开头的元素大小，所以我们可以移动[mn,mx]到达任意一个[mn+a,mx+a]的区间，那么我们要求的就是有多少个a可以满足mn+a>=lower and mx+a<=upper的条件。解得lower-mn<=a<=upper-mx，所以答案就是(upper-mx-(lower-mn)+1)
        # 注意，最开始计算的时候假设起始点是0，所以mn和mx都应为0
        mn, mx = 0, 0
        tmp = 0
        for i in differences:
            tmp += i
            mn = myMin(mn, tmp)
            mx = myMax(mx, tmp)
        return myMax(0, upper-(mx+(lower-mn))+1)

if __name__ == "__main__":
    s = Solution()
    differences = [1,-3,4]
    lower, upper = 1, 6
    print(s.numberOfArrays(differences, lower, upper))
