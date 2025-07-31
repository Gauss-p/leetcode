from typing import List

class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # 利用定义，我们可以知道derived[i]=origional[i]^origional[i+1]，并且以此类推，derived[i+1]^derived[i+2]^...^derived[n-1]^derived[0]^derived[1]^...^derived[i-1] = origional[i+1]^origional[i]，因为异或过程中，两两相同的数字都抵消掉了，因此我们判断上述两个值是否相等，如果不相等，就说明出现矛盾，返回False，否则继续判断
        # 可以发现，上述两个式子的左侧合起来就是derived中的所有数字，因此对于每一个derived[i]，我们都可以直接求出对应第二个式子的值，也就是XOR(derived)^derived[i]，即在所有数字的异或中去除derived[i]即可
        allXor = 0
        for i in derived:
            allXor ^= i
        for i in derived:
            if i != allXor^i:
                return False
        return True

if __name__ == "__main__":
    s = Solution()
    derived = [1,1,0]
    print(s.doesValidArrayExist(derived))
