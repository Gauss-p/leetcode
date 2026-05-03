class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        cur = s
        for i in range(len(s)):
            cur = cur[1:]+cur[0]
            if cur == goal:
                return True
        return False

if __name__ == "__main__":
    sl = Solution()
    s = "abcde"
    goal = "cdeab"
    print(sl.rotateString(s, goal))
