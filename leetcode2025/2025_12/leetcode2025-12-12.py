from typing import List

class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        events.sort(key = lambda x:(int(x[1]), (1 if x[0]=="MESSAGE" else 0)))
        mentions = [0]*numberOfUsers
        curOnline = [1]*numberOfUsers
        willOn = []
        for e, timeStamp, mStr in events:
            while willOn and willOn[0][0] <= int(timeStamp):
                curOnline[willOn[0][1]] = 1
                willOn.pop(0)
            if e == "MESSAGE":
                if mStr == "ALL":
                    for i in range(numberOfUsers):
                        mentions[i] += 1
                elif mStr == "HERE":
                    for i in range(numberOfUsers):
                        if curOnline[i] == 1:
                            mentions[i] += 1
                else:
                    for i in mStr.split(' '):
                        mentions[int(i[2:])] += 1
            else:
                curOnline[int(mStr)] = 0
                willOn.append((int(timeStamp)+60, int(mStr)))
        return mentions

if __name__ == "__main__":
    s = Solution()
    numberOfUsers = 2
    events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]
    print(s.countMentions(numberOfUsers, events))
