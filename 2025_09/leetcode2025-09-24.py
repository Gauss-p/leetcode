from collections import defaultdict

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # 针对该题目可以直接采用完全的竖式除法模拟的方式来计算，也就是说，对于最开始的整数可以完全模拟。维护一个当前被除数curNum，在对于原被除数的整数部分处理的时候，每一次就将curNum多加上一位，然后进行计算。在计算的时候，只要curNum>=denominator，就可以将curNum//denominator的值加入答案中。但是注意，在第一次加入答案之后，对于每一个接下来的位，我们都需要在res中加入一个数字，就算curNum<denominator，也还需要加入一个占位符0
        # 然后对于小数部分进行处理，和整数部分大体相同，但是在计算的时候不单单要维护当前被除数，还需要记录所有的被除数出现的位置，这样，只要发现一个之前出现过的被除数，就说明出现循环节，直接退出循环，同时在res中上一次出现相同被除数的位置加入(，并在最后加入)，最后直接返回即可
        flag = False
        res = ""
        if numerator*denominator < 0:
            res += '-'
        numerator = abs(numerator)
        denominator = abs(denominator)
        s = str(numerator)

        curNum = 0
        for i in s:
            curNum = curNum*10+int(i)
            if flag or curNum >= denominator:
                flag = True
                res += str(curNum//denominator)
                curNum = curNum%denominator
            elif flag and curNum < denominator:
                res += '0'
        if len(res) == 0:
            res += "0"
        if curNum == 0:
            return res

        res += "."
        visited = defaultdict(int)
        indx = len(res)
        while curNum not in visited:
            if curNum == 0:
                return res
            visited[curNum] = indx
            curNum = curNum*10
            if curNum >= denominator:
                res += str(curNum//denominator)
                curNum = curNum%denominator
            else:
                res += '0'
            indx += 1

        if curNum == 0:
            return res
        res = res[:visited[curNum]]+'('+res[visited[curNum]:]+')'
        return res

if __name__ == "__main__":
    s = Solution()
    numerator = 4
    denominator = 333
    print(s.fractionToDecimal(numerator, denominator))
