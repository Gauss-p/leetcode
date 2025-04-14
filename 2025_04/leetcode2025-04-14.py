from typing import List

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        # 由题意可知，arr[j]-a<=arr[i]<=arr[j]+a，且arr[k]-c<=arr[i]<=arr[k]+c，又因为arr[i]最小不可能到-1，最大不可能到max(arr)+1，所以0<=arr[i]<=max(arr)，所以如果已经得到arr[j]=y，arr[k]=z，那么可知arr[i]的范围就是[max(0, y-a, z-c), min(max(arr), y+a, z+c)]，为了说明方便，令l=max(0, y-a, z-c)，r=min(max(arr), y+a, z+c)
        # 那么为了得到在该区间内的所有数的总数量，我们可以用计数的思路，定义cnt，cnt[i]表示在arr中数字i的出现次数，那么要求的答案就是sum(cnt[l:r+1])，为了一次性求出答案，我们用前缀和数组s，s[i]为sum(cnt[:i])，答案就是(s[r+1]-s[l])。同时为了计算方便，我们将arr排序，所以如果需要多加入一个数字y，数组s中位于y+1之后的所有数字只需要加上1即可，相当于cnt[y]加了1
        n = len(arr)
        mx = max(arr)
        res = 0
        s = [0]*(mx+2) # 前缀和数组
        for j in range(n):
            for k in range(j+1, n):
                y, z = arr[j], arr[k]
                if abs(y-z) > b:
                    continue
                # 确定范围
                l = max(0, y-a, z-c)
                r = min(mx, y+a, z+c)
                res += max(s[r+1]-s[l], 0)
            for i in range(arr[j]+1, mx+2):
                s[i] += 1
        return res


        # n = len(arr)
        # res = 0
        # for i in range(n):
        #     for j in range(i+1, n):
        #         for k in range(j+1, n):
        #             if abs(arr[i]-arr[j])<=a and abs(arr[j]-arr[k])<=b and abs(arr[i]-arr[k])<=c:
        #                 res += 1
        # return res

if __name__ == "__main__":
    s = Solution()
    arr = [3,0,1,1,9,7]
    a, b, c = 7, 2, 3
    print(s.countGoodTriplets(arr, a, b, c))
