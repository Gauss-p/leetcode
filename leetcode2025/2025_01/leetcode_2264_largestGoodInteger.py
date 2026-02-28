class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        res = -1
        for i in range(1, n-1):
            if num[i-1] == num[i] and num[i] == num[i+1]:
                if res<int(num[i]):
                    res = int(num[i])
        return 3*str(res) if res!=-1 else ""

if __name__ == "__main__":
    s = Solution()
    num = "6777133339"
    print(s.largestGoodInteger(num))
