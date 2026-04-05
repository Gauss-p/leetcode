/bin/bash: line 1: :w: command not found

class Solution:
    def judgeCircle(self, moves: str) -> bool:
        cnt = Counter(moves)
        return cnt['R']==cnt['L'] and cnt['U']==cnt['D']

if __name__ == "__main__":
    s = Solution()
    moves = "UD"
    print(s.judgeCircle(moves))
