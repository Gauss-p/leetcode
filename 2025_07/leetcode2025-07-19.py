from typing import List
from collections import defaultdict

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        cnt = defaultdict(int)
        for i in folder:
            cur = i.split('/')
            flag = True
            for j in range(len(cur)):
                if '/'.join(cur[:j+1]) in cnt:
                    flag = False
                    break
            if flag:
                cnt[i] += 1
        return list(cnt.keys())

if __name__ == "__main__":
    s = Solution()
    folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    print(s.removeSubfolders(folder))
