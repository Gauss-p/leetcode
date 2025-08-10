from collections import Counter

maxNum = 1_000_000_000
pow2 = [1]
while pow2[-1]<maxNum:
    pow2.append(pow2[-1]<<1)

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        # 预处理出所有2的幂，然后逐个判断是否可以由n重排构成即可
        cur = Counter(str(n))
        for x in pow2:
            if cur == Counter(str(x)):
                return True
        return False

if __name__ == "__main__":
    s = Solution()
    n = 61
    print(s.reorderedPowerOf2(n))
