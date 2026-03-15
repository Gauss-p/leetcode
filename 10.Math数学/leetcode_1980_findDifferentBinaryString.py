from typing import List

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        # 利用对角线构造法，由于nums长度为n，且nums中每个元素长度都为n，故如果将其从上到下排列，就可以排成一个正方形矩阵，此时，为了找到一个与所有数字都不同的数字，可以将左上到右下的对角线上的所有数字取出，并将每个数字都反转，那么此时形成的数字即可同时满足：长度为n，且与其他各个数字至少有一个位置不同
        res = ""
        for i in range(len(nums)):
            res += str(int(nums[i][i])^1)
        return res

if __name__ == "__main__":
    s = Solution()
    nums = ["01","10"]
    print(s.findDifferentBinaryString(nums))
