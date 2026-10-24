class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        aad = sum(days[:int(arriveAlice[:2])])+int(arriveAlice[3:])
        lad = sum(days[:int(leaveAlice[:2])])+int(leaveAlice[3:])
        abd = sum(days[:int(arriveBob[:2])])+int(arriveBob[3:])
        lbd = sum(days[:int(leaveBob[:2])])+int(leaveBob[3:])

        start = max(aad, abd)
        end = min(lad, lbd)
        return max(0, end-start+1)

if __name__ == "__main__":
    s = Solution()
    arriveAlice = "08-15"
    leaveAlice = "08-18"
    arriveBob = "08-16"
    leaveBob = "08-19"
    print(s.countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob))
