from collections import defaultdict

class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        # 为了保证将某种字符的所有位置都选在一个子字符串中，可以对于每一种字母，都找到它在字符串中出现的最左侧位置和最右侧位置，只要一个区间包含了它的最左侧和最右侧位置在内，即可保证s中所有的这种字母都被包含在了这个区间内。
        # 接下来从每一个字母开始进行计算，首先对于这个字母本身的最左最右出现位置即可得到一个最小的包含所有该字母的区间，但这并不够，因为在这个区间内可能出现其他的字母，可能只包含了这些字母的一部分，因此需要根据区间内的其他字母的最左和最右位置重新确定当前区间的最左和最右端点。当对于最初的区间内所有元素都计算一遍左右端点后，可能继续出现新字符，因此需要用同样的方式继续更新，直到没有新字符出现为止。这个操作可以通过维护一个总的大区间[l,r]和一个已经更新过的区间[nl,nr]来实现，最初，l,r分别置为当前字符的最左和最右出现位置，nl和nr均设置为l，接着，每次循环都需要在nl和nr两个位置之中选一个位置对应的字符信息更新l和r的位置，这里按照先左后右的顺序更新，当[nl,nr]不再是[l,r]的子区间时，说明子字符串已经寻找完毕，退出循环即可
        pos = defaultdict(list)
        for i,c in enumerate(s):
            if c not in pos:
                pos[c] = [i,i]
            else:
                pos[c][1] = i
        
        spaces = []
        for c in pos.keys():
            l, r = pos[c]
            nl, nr = l, l
            while nl>=l or nr<=r:
                # 只要还未完全覆盖[l,r]区间，就需要继续更新
                indx = nl if nl>=l else nr
                nc = s[indx]
                if pos[nc][0] < l:
                    l = pos[nc][0]
                if pos[nc][1] > r:
                    r = pos[nc][1]
                if indx == nl:
                    nl -= 1
                if indx == nr:
                    nr += 1
            spaces.append([l, r])

        spaces.sort(key = lambda x:x[1])
        res = []
        end = -1
        for l,r in spaces:
            if l > end:
                res.append(s[l:r+1])
                end = r
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "adefaddaccc"
    print(sl.maxNumOfSubstrings(s))
