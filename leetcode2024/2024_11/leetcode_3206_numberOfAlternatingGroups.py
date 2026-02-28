class Solution:
    def numberOfAlternatingGroups(self, colors):
        n = len(colors)
        res = 0
        for i in range(n):
            if colors[i] != colors[(i-1+n)%n] and colors[i] != colors[(i+1)%n]:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    colors = [0,1,0,0,1]
    print(s.numberOfAlternatingGroups(colors))
