class Solution:
    def minMaxDifference(self, num: int) -> int:
        # 可以选择直接计算结果，那么我们需要分两种情况：
        # 1.num的第一个数字是9，那么我们可以发现，如果要将num变成最大值，就需要找到第一个非9的数字first，将它全部变成9，但是最小值就不能用这种思路，而需要将num中所有的9变成0，那么相减之后，对于每一个位置而言，如果该位置是9，那么答案中对应的位置就是9-0=9，如果该位置是第一个非9的数字first，那么答案就是9-first，因为最大值中该位置是9，最小值中因为我们变了9，就无法变first，那么最小值中该位置就是原值first，相减即为9-first，而对于既不是9也不是first的位置，由于它们在最小值和最大值中都没变化，相减之后就是0
        # 2.num的第一个数字不是9，记为first，那么最大值就是将num中所有的first全部变成9，最小值就是将num中所有的first全部变成0，那么在答案中对于每一个位置，如果该位置是原先first，那么相减之后就是9-0=9，否则因为都没有变化，所以相减之后就是0
        s = str(num)
        flag = (s[0]=='9') # True即代表第一种情况，False即代表第二种情况
        res = ""
        first = ""
        for i in s:
            if flag:
                if i == '9':
                    # 对于9的位置，答案就是9-0=9
                    res += '9'
                else:
                    if first == "" or i == first:
                        # 对于所有与num中第一个非9数字相同的位置，答案就是9-first
                        first = i
                        res += str(9-int(i))
                    else:
                        # 如果两者都不是，答案就是0
                        res += '0'
            else:
                if first == "" or i == first:
                    # 如果当前数字和num中第一个数字相同，那么答案就是9-0=9
                    first = i
                    res += '9'
                else:
                    # 否则因没有变化，答案就是0
                    res += '0'
        return int(res)

if __name__ == "__main__":
    s = Solution()
    num = 11891
    print(s.minMaxDifference(num))
