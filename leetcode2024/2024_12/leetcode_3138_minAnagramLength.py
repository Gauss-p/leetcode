class Solution:
    def minAnagramLength(self, s: str) -> int:
        n = len(s)
        for l in range(1, n+1):
            if n%l != 0:
                continue
            first = ''.join(sorted(list(s[:l])))
            # flag = True
            for b in range(l, n, l):
                tmp = ''.join(sorted(list(s[b:b+l])))
                if tmp != first:
                    # flag = False
                    break
            else:
                return l
            # if flag:
                # return l
        return n

if __name__ == "__main__":
    sl = Solution()
    s = "abba"
    print(sl.minAnagramLength(s))
