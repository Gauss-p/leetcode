class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return abs(moves.count('R')-moves.count('L'))+moves.count('_')

if __name__ == "__main__":
    s = Solution()
    moves = "L_RL__R"
    print(s.furthestDistanceFromOrigin(moves))
