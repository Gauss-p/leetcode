from string import *

class Solution:
    def kthCharacter(self, k: int) -> str:
        w = "a"
        lowers = ascii_lowercase
        while len(w)<k:
            cur = ""
            for i in w:
                indx = ord(i)-ord('a')
                cur += lowers[(indx+1)%26]
            w += cur
        return w[k-1]

if __name__ == "__main__":
    s = Solution()
    k = 5
    print(s.kthCharacter(k))
