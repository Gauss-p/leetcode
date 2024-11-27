class Solution:
    def numberOfAlternatingGroups(self, colors, k: int) -> int:
        n = len(colors)
        cnt, ans = 1, 0
        for i in range(-k+2, n):
            if colors[i] != colors[i-1]:
                cnt += 1
            else:
                cnt = 1
            if cnt >= k:
                ans += 1
        return ans

if __name__ == "__main__":
    s = Solution()
    colors = [0,1,0,1,0]
    k = 3
    print(s.numberOfAlternatingGroups(colors, k))
