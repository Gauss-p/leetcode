from typing import List

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        mp = {'+':1, '-':-1}
        return sum(mp[i[1]] for i in operations)

if __name__ == "__main__":
    s = Solution()
    operations = ["--X","X++","X++"]
    print(s.finalValueAfterOperations(operations))
