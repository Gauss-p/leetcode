from typing import List

rows = [[1]]
for i in range(1, 30):
    cur = [1]
    for j in range(len(rows[i-1])-1):
        cur.append(rows[i-1][j]+rows[i-1][j+1])
    cur.append(1)
    rows.append(cur)

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        return rows[:numRows]

if __name__ == "__main__":
    s = Solution()
    numRows = 5
    print(s.generate(numRows))
