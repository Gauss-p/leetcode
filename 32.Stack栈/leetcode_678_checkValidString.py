class Solution:
    def checkValidString(self, s: str) -> bool:
        # 遇到右括号先配栈中左括号，如果没有，就配栈中星号，如果还是没有，说明右括号太多，返回False
        # 最后需要判断星号变成空或右括号的情况，也就是将星号栈中的元素和左括号栈中的元素一一进行匹配，但这里需要注意，不能仅仅通过两种元素的个数简单判断，而需要根据其出现顺序进行判断，例如，'*('就是一个无法匹配的字符串，因为虽然有剩余星号和左括号，但两者出现顺序并不符合左括号在前，星号在后的规则。因此最后根据两个栈中存下的位置判断即可
        st = []
        stars = []
        for i,c in enumerate(s):
            if c == '(':
                st.append(i)
            elif c == '*':
                stars.append(i)
            else:
                if len(st):
                    st.pop()
                else:
                    if len(stars):
                        stars.pop()
                    else:
                        return False

        indx = 0
        for i in st:
            while indx<len(stars) and stars[indx]<i:
                indx += 1
            # 双指针，如果星号栈中的指针移到了栈尾，即无法与左括号配对，返回False
            if indx == len(stars):
                return False
            indx += 1
        return True

if __name__ == "__main__":
    sl = Solution()
    s = "(*)"
    print(sl.checkValidString(s))
