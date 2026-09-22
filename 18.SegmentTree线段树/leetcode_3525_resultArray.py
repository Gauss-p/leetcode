from typing import List

class Data:
    def __init__(self, val, cnt):
        self.val = val
        self.cnt = cnt

class Node:
    def __init__(self, l, r, left=None, right=None):
        self.l = l
        self.r = r
        self.left = left
        self.right = right
        self.mid = (l+r)//2
        self.data = None
    
class SegmentTree:
    # 用线段树的思路，每一个节点对应一个区间，而其中存储的信息即为一个长度为k的列表，对这个区间内所有可能的前缀分别求积，将所有积模除k得到的值在列表对应位置累加1即可得到。
    # 线段树中最重要的是根据一个区间的两个子区间统计出来的信息推出当前区间的信息。注意到由于统计的信息全部都是有关前缀的，因此对于区间[l,r]的左半边，其前缀就等同于[l,(l+r)//2]的所有前缀，即可以直接用上当前节点的左子节点对应的信息，之后对于前缀结尾落在[l,r]的右半边的情况，它们的积可以拆成两部分，一部分是[l,(l+r)//2]，另一部分即为中点到该前缀结尾的地方，可以发现，前者的积是一个定值，而后者的积实际上等同于[(l+r)//2,r]中所有前缀对应的信息。因此，当需要将两个区间拼接成一个更大区间时，大区间的信息就需要分两种情况加起来：1.直接复制左区间的信息；2.将右区间的信息索引乘以左区间之积后，在得到的新的索引位置进行累加
    # 查询时即需要将待查询区间分割成已经计算好的区间，按照上面的思路合并信息即可
    def __init__(self, nums, k):
        self.nums = nums
        self.k = k
        n = len(nums)
        root = Node(0, n-1)
        self.build(root)
        self.root = root

    def build(self, node):
        if node.l == node.r:
            val = self.nums[node.l]%self.k
            cnt = [0]*self.k
            cnt[val] = 1
            node.data = Data(val, cnt)
            return

        leftNode = Node(node.l, node.mid)
        self.build(leftNode)
        rightNode = Node(node.mid+1, node.r)
        self.build(rightNode)
        node.left = leftNode
        node.right = rightNode
        self.maintain(node)
    
    def maintain(self, node):
        node.data = self.merge(node.left.data, node.right.data)
    
    def merge(self, leftData, rightData):
        k = self.k
        lv = leftData.val
        curCnt = leftData.cnt.copy()
        for i,c in enumerate(rightData.cnt):
            curCnt[(lv*i)%k] += c
        return Data((lv*rightData.val)%k, curCnt)
    
    def update(self, node, indx, newV):
        if node.l == node.r:
            v, cnt = newV%self.k, [0]*self.k
            cnt[v] = 1
            node.data = Data(v, cnt)
            return
        if indx <= node.mid:
            self.update(node.left, indx, newV)
        else:
            self.update(node.right, indx, newV)
        self.maintain(node)

    def query(self, node, L, R):
        if L <= node.l and node.r <= R:
            return node.data
        if node.mid < L:
            return self.query(node.right, L, R)
        if R <= node.mid:
            return self.query(node.left, L, R)

        lData = self.query(node.left, L, R)
        rData = self.query(node.right, L, R)
        return self.merge(lData, rData)

class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)
        st = SegmentTree(nums, k)
        res = []
        for indx, v, start, x in queries:
            st.update(st.root, indx, v)
            curData = st.query(st.root, start, n-1)
            res.append(curData.cnt[x])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4,5]
    k = 3
    queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]
    print(s.resultArray(nums, k, queries))
