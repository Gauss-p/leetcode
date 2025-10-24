class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def is_balanced(x):
            # 判断x是否平衡
            cnt = [0]*10
            while x:
                if cnt[x%10] >= x%10:
                    return False
                cnt[x%10] += 1
                x //= 10
            for i in range(10):
                if cnt[i] > 0 and cnt[i] != i:
                    return False
            return True
        
        res = n+1
        while not is_balanced(res):
            res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 1
    print(s.nextBeautifulNumber(n))
