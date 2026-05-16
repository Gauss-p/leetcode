class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return '-'.join(list(map(lambda x:bin(int(x))[2:], date.split('-'))))

if __name__ == "__main__":
    s = Solution()
    date = "2080-02-29"
    print(s.convertDateToBinary(date))
