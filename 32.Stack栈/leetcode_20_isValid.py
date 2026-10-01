class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(', '}':'{', ']':'['}
        st = []
        for c in s:
            if c in '({[':
                st.append(c)
            else:
                if len(st) and st[-1] == mp[c]:
                    st.pop()
                else:
                    return False
        return len(st) == 0

if __name__ == "__main__":
    sl = Solution()
    s = "()"
    print(sl.isValid(s))
