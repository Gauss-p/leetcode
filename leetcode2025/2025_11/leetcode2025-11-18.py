from typing import List

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        # 分析题目，如果当前位为0，那么就可以向后跳1步，否则必须向后跳2步
        # 为了保证最后一个字符是一比特字符，先将bits中最后一个字符去除，然后用上述方法模拟，看是否能够到达最右边的哨兵即可判断是否能够完成分割
        bits = bits[:-1]
        n = len(bits)
        indx = 0
        while indx<n:
            if bits[indx] == 0:
                indx += 1
            else:
                if indx+1 < n:
                    indx += 2
                else:
                    break
        return indx==n

if __name__ == "__main__":
    s = Solution()
    bits = [1,0,0]
    print(s.isOneBitCharacter(bits))
