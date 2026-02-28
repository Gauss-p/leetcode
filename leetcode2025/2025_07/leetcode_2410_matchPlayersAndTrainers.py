from typing import List

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        # 贪心，每一个trainer最好匹配最小的player，排序后双指针为每一个可能的player匹配一个合适的trainer即可
        players.sort()
        trainers.sort()
        n = len(trainers)
        m = len(players)
        j = 0
        for i in range(n):
            if j<m and players[j] <= trainers[i]:
                j += 1
        return j

if __name__ == "__main__":
    s = Solution()
    players = [4,7,9]
    trainers = [8,2,5,8]
    print(s.matchPlayersAndTrainers(players, trainers))
