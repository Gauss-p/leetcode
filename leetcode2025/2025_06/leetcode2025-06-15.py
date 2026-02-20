class Solution:
    def maxDiff(self, num: int) -> int:
        # 根据题目，num的最大值就是将num中所有的第一个非9的数字变成9
        # 并且num的最小值有两种情况：1.num的第一个数字是1，此时num的最小值就是将num中所有的第一个非1的数字变成0；2.num的第一个数字大于1，此时num的最小值就是将num中所有和第一个数字相同的数字变成1
        # 求出两个最值之后相减即可
        s = str(num)
        mx = s
        mn = s
        n = len(s)
        for i in range(n):
            if mx[i] != '9':
                mx = mx.replace(mx[i], '9')
                break
        if mn[0] != '1':
            mn = mn.replace(mn[0], '1')
        else:
            for i in range(n):
                if mn[i] > '1':
                    mn = mn.replace(mn[i], '0')
                    break
        return int(mx)-int(mn)

        
        # 或者我们可以直接计算答案，分3种情况：
        # 1.num的第一个数字是9，那么对于每一个位置，如果该位置是9，那么最大就是9，最小就变成1，答案对应的位置就是8，如果该位置是第一个非9的数字，那么最大就是9，最小的情况因为在num中将9变为了1，就不能改变这个数字，因此最小就是它本身，答案对应的位置就是9-当前数字，对于其他情况，答案都是0
        # 2.num的第一个数字是1，那么对于每一个位置，如果该位置是1，那么最大就是9，最小就是1，答案对应的位置就是8，如果该位置是第一个非1的数字，那么最大的情况因为在num中将1变成了9，就不能改变这个数字，因此最大就是它本身，但是最小的情况是可以改变它的，因此最小就是0，答案对应的位置就是该数字本身，对于其他情况，答案都是0
        # 3.num的第一个数字既不是9也不是0，那么对于每一个位置，如果该位置和num的第一个数字相同，最大可以变成9，最小可以变成1，答案就是8，对于其他情况，答案对应的位置都是0
        # s = str(num)
        # n = len(s)
        # first, second = "", ""
        # for i in range(n):
        #     if first == "":
        #         first = s[i]
        #     elif first == '1' and second == "" and s[i] != first:
        #         if s[i] == '0':
        #             continue
        #         else:
        #             second = s[i]
        #     elif first == '9' and second == "" and s[i] != first:
        #         second = s[i]

        # flag = (s[0] == '9')
        # res = ""
        # for i in s:
        #     if first == '9':
        #         if i == first:
        #             res += '8'
        #         elif i == second:
        #             res += str(9-int(i))
        #         else:
        #             res += '0'

        #     elif first == '1':
        #         if i == first:
        #             res += '8'
        #         elif i == second:
        #             res += second
        #         else:
        #             res += '0'

        #     else:
        #         if i == first:
        #             res += '8'
        #         else:
        #             res += '0'
        # return int(res)

if __name__ == "__main__":
    s = Solution()
    num = 555
    print(s.maxDiff(num))
