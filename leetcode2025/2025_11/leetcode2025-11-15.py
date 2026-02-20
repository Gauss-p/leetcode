class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # 分析题目，我们需要让一个字符串中0的个数的平方小于等于1的个数，也就是说，我们需要让cnt0*cnt0<=cnt1，但是由于cnt1<=n，所以可以推出：cnt0 <= sqrt(n)，因此，我们可以以每一个位置为左端点，枚举字符串中可能出现的0的个数，同时累加有这么多个0，同时1的个数满足要求的字符串总数，这样，总的时间复杂度就可以控制在O(n*sqrt(n))
        # 所以首先我们要求出有确定个数的0的字符串，然后再在其中求1的个数满足要求的字符串个数
        # 接下来，如果已经知道以位置i为起点的字符串[i,j]中存在cnt0个0，且s[j]='0'，那么以i为左端点，且字符串中有且仅有cnt0个0的字符串有多少个呢？可以发现，我们需要知道的其实就是满足条件的右端点个数，那么为了保证字符串中只有cnt0个0，我们需要保证在j之后添加的所有数字都是1，因此可以发现，最大的一个右端点只能是j之后的最近的一个0的位置，因为只有在这个位置之前且在j之后的所有位置才都是1
        # 综上，我们需要构建一个数组用来统计每一个位置的右侧最近的一个0的位置，我们称这个数组为nextZero，则nextZero[i]所存储的值就是一个索引j，它是所有满足j>i且s[j]='0'的最小值。这样，对于上面的问题，如果已知字符串[i,j]中一共有cnt0个0，且s[j]='0'，求以i为左端点且字符串中只有cnt0个0的字符串个数，那么就可以直接利用nextZero数组算出，即nextZero[j]-j，因为根据定义可知，在区间[j+1,nextZero[j]]中，所有索引对应的s中的字符都是1
        # 最后，我们需要限定1的个数满足要求。由于右端点已经被限定在[j, nextZero[j])中，因此可以变动的1的个数仅仅只有nextZero[j]-j，而我们需要做的，就是在这样的变动范围内再加一个限制，使得cnt1始终大于等于cnt0*cnt0。如果从最大的右端点向左移动的思路看，可以发现：1.最大右端点对应的1的个数是nextZero[j]-i-cnt0；2.最大可以删除的1的个数是nextZero[j]-j；3.cnt1最多只能减少(cnt1-cnt0*cnt0)才能保证cnt1>=cnt0*cnt0，也就是，为了保证cnt1>=cnt0*cnt0，删除的1的数量应当在区间[0, cnt1-cnt0*cnt0]中。综上可以发现，对于一个起点i，满足字符串中0的个数为cnt0的1显著字符串的数量为：min(nextZero[j]-j, cnt1-cnt0*cnt0+1)
        # 因此对于每一个可能的左端点i和0的个数cnt0，都计算一次答案即可

        myMin = lambda x,y : x if x<y else y

        n = len(s)
        pos = n
        nextZero = [n]*n
        for i in range(n-1, -1, -1):
            nextZero[i] = pos # 右侧最近的0的位置
            if s[i] == '0':
                pos = i

        res = 0
        for i in range(n):
            cnt0 = (s[i]=='0')
            j = i
            while j<n and cnt0*cnt0<=n:
                cnt1 = (nextZero[j]-i)-cnt0 # 最大右端点对应的1的个数
                if cnt1 >= cnt0*cnt0: # 满足条件
                    res += myMin(nextZero[j]-j, cnt1-cnt0*cnt0+1)
                j = nextZero[j] # 移动到下一个0的位置
                cnt0 += 1
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "00011"
    print(sl.numberOfSubstrings(s))
