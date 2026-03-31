class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        # 首先以每一个str1中是T的位置为开始，在res中填入一个str2，不过为了防止后面填入的str2将前面的覆盖，还需要重新循环一次，判断每一个是T的位置开始，长度为m的子字符串是否等于str2，只要不等，说明给出的str1是矛盾的，返回空字符串
        # 最后，先将其他所有的空位填成a，然后对于str1中所有是F的位置，如果从该位置开始长度为m的子字符串等于str2，那么就从这个子字符串的最后开始向前循环，只要发现第1个a就直接将其变成b，这样就既保证了res的字典序最小，同时保证了F的要求
        n, m = len(str1), len(str2)
        res = "a"*(n+m-1)
        # 模拟填入
        for i in range(n):
            if str1[i] == 'T':
                res = res[:i]+str2+res[i+m:]
        
        # 检测矛盾
        for i in range(n):
            if str1[i] == 'T':
                if res[i:i+m] != str2:
                    return ''
        
        # 处理F位置
        for i in range(n):
            if str1[i] == 'F' and res[i:i+m] == str2:
                flag = False
                for j in range(i+m-1, i-1, -1):
                    if res[j] == 'a':
                        res = res[:j]+'b'+res[j+1:]
                        flag = True
                        break
                if not flag:
                    return ""
        return res

if __name__ == "__main__":
    s = Solution()
    str1, str2 = "TFTF", "ab"
    print(s.generateString(str1, str2))
