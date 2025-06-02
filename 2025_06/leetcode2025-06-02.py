from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        # 将给出的ratings分成单调递增和单调递减两个部分考虑，根据题目可知，对于单调递增的列表，每两个小朋友中后面一个都比前面一个要多分一个糖果，对于单调递减列表，每两个小朋友中前面一个都比后面一个要多分一个糖果
        # 因此我们可以先考虑所有的单调递增子序列，将其按照[1,2,3,...]的方式赋值，将所有值存入increase列表中，再考虑所有单调递减子序列，将其按照[...,3,2,1]的方式赋值，将所有值存入decrease列表中，最后对于每一个位置求出它在increase和decrease中的最大值，就可以得到这个小朋友真正应该分到的糖果数量，将每一个糖果数量相加即可
        # 之所以可以求最大值，是因为按照这样排列的每一个位置都已经让其尽可能小了，即对于每一个位置的答案res[i]都可以满足res[i]>=increase[i]且res[i]>=decrease[i]，所以res[i]的最小值就是max(increase[i], decrease[i])
        n = len(ratings)
        increase, decrease = [1]*n, [1]*n
        for i in range(n-1):
            if ratings[i] < ratings[i+1]:
                increase[i+1] = increase[i]+1
        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                decrease[i] = decrease[i+1]+1
                
        res = 0
        for i in range(n):
            res += max(increase[i], decrease[i])
        return res

if __name__ == "__main__":
    s = Solution()
    ratings = [1,0,2]
    print(s.candy(ratings))
