from typing import List
from collections import Counter

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 第二种方法：原地修改，我们的目的是要将nums排列成[0,0,...,0, 1,1,...,1, 2,2,...,2]的形式，我们用n0表示连续0的结尾位置，用n1表示连续1的结尾位置，用连续2表示连续2的结尾位置，例如如果nums当前是[0,1,1,1,2,2,1,0]，可以发现只有nums[:6]是已经排好的，那么n0=1,n1=4,n2=6，
        # 这样，如果在之后的遍历中又发现了一个0，就可以将0插入到当前n0对应的位置，同时将n1和n2的位置分别变为1和2，并将其向后移动一个位置，目的是为了给前面刚加入的0让出位置；同理，如果在之后的遍历中又发现一个1，直接插入对前面的所有0是没有影响的，因此只需将n1对应的位置改为1，并将n2的位置改为2，同时将n2向后移动一位；而如果又发现了一个2，则只需将n2位置改为2，并将n2向后移动一位即可
        # 总结上面的方法，1.如果发现nums[i]=0，那么将nums[n0]=0,nums[n1]=1,nums[n2]=2，同时n0,n1,n2都分别加1；2.如果发现nums[i]=1，那么将nums[n1]=1,nums[n2]=2，同时n1,n2都分别加1；3.如果发现nums[i]=2，那么将nums[n2]=2，同时将n2加1即可
        n0, n1, n2 = 0, 0, 0
        for i in range(len(nums)):
            if nums[i] == 0:
                nums[n2] = 2
                nums[n1] = 1
                nums[n0] = 0
                n2 += 1
                n1 += 1
                n0 += 1
            elif nums[i] == 1:
                nums[n2] = 2
                nums[n1] = 1
                n2 += 1
                n1 += 1
            else:
                nums[n2] = 2
                n2 += 1
        
        # 第一种方法：暴力，首先用cnt统计nums中各个数字出现的个数，因为只有三个数字，所以可以直接用cnt[0]个0，cnt[1]个1，cnt[2]个2合并起来，拼出一个新的nums即可
        # cnt = Counter(nums)
        # indx = 0
        # for i in range(3):
        #     for j in range(cnt[i]):
        #         nums[indx] = i
        #         indx += 1

if __name__ == "__main__":
    s = Solution()
    nums = [2,0,2,1,1,0]
    s.sortColors(nums)
    print(nums)
