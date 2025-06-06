class Solution:
    def robotWithString(self, s: str) -> str:
        # 贪心地想，对于s中每一个位置，如果它比后面的所有字符都要小，那么肯定要将它加入t的末尾并弹出，因为如果继续往后面循环，只会让弹出的字符变得更大，而无法满足题目要求的“字典序最小”
        # 所以，我们可以先求出一个列表用来存储每一个位置开始的后缀中的最小字符，然后再一次循环所有位置，同时用栈来记录t中的元素，那么对于当前位置i，首先就要将i加入t中，接下来，如果t的末尾元素小于等于i+1开始的后缀的最小字符，那么就将t的末尾元素弹出并加入答案，一直到t的末尾不再有比后面元素还小的字符或t中没有字符了为止，这样才能保证每一个位置都放置的是字典序最小的元素
        n = len(s)
        back_min = ["z"]*(n+1) # 预处理每一个位置及其之后的所有元素最小值
        for i in range(n-1, -1, -1):
            back_min[i] = min(s[i], back_min[i+1])
        
        res = []
        st = [] # 用栈来代替t
        for i in range(n):
            st.append(s[i])
            while st and st[-1] <= back_min[i+1]:
                # 每一次都将比后面所有值都小的元素弹出并加入答案
                res.append(st.pop())
        return "".join(res)

if __name__ == "__main__":
    sl = Solution()
    s = "bac"
    print(sl.robotWithString(s))
