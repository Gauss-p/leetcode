from typing import List

class TrieNode:
    def __init__(self):
        self.son = {}
        self.name = ""
        self.deleted = False

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        # 思路是这样的，为了判断两个子文件夹集合是否相同并具有相同的子文件夹结构，我们不可能将两个子树遍历一遍进行判断，因此我们可以想到将这个树转化成一个字符串，这样判断两个子文件夹集合是否相同就直接判断两个字符串是否相等即可，但是我们还需要判断这两个子树是否拥有相同的子文件夹结构，因此单纯记录每一个节点是不行的，我们可以用小括号来表示父子关系，在前序遍历中，用'('表示向下一层，用')'表示向上一层即可。比如，如果根节点是a，下面有并列的两个节点b和c，这样该树的字符串就是"a(b)(c)"，如果根节点是a，它的孩子是b，b的孩子是c，那么该树的字符串就是"a(b(c))"，因此我们可以发现，对于任何一个节点x，以它为根节点的子树的字符串就等于："当前节点的字符+(第一个子节点为根节点的树字符串)+(第二个子节点为根节点的树字符串)+···+(最后一个子节点为根节点的树字符串)"，也就是，如果我们称以一个字符为a的节点node为根节点的子树字符串为TreeStr(node)，并且node的子节点为s1,s2,...,sn，那么TreeStr(node)='a'+'('+TreeStr(s1)+')'+···+'('+TreeStr(sn)+')'
        # 那么根据这个递推关系式，我们就可以用dfs的方式递归着计算出以任意一个节点为根的子树字符串，但是出现了一个问题，就是如果两个节点的子节点虽然都并列，而且内容都相同，但是记录的顺序不同，那我们其实也无法通过判断字符串是否相同来判断两个子树是否相同，因此我们可以采用将里面的所有字符按从小到大的顺序排列，这样就可以更简单地判断两个子树是否相同了
        # 在dfs函数中，我们可以在生成子树字符串的同时来判断是否出现重复的字符串，如果出现，我们就需要将该节点先标记为删除，然后再继续查找，因此，我们可以用一个字典来记录一下信息：之前查到的所有字符串和其对应的根节点，其中前者是键，后者是值，这样，我们只要发现新生成的字符串已经出现在该字典中，就说明查到了一对重复的子树，然后将字典中对应的上一次查找到的根节点和当前根节点都标记删除即可
        # 接下来，在对所有的节点都生成过一次子树字符串后，我们就可以按照标记的是否删除来重新还原删除后的整个文件系统，我们仍然可以考虑dfs算法，由于题目不要求顺序，因此我们只需要从头到尾将所有的路径保存即可，使用一个path来维护当前的路径，每一次加入当前节点，然后在对该节点的子节点操作完后将该节点同path中删除即可，也就是恢复现场
        root = TrieNode() # 这里用到字典树，也就是每一个节点是一个字典，保存了它的所有孩子，其中键是节点的字符，值就是一个节点，类型同为TrieNode
        for p in paths:
            cur = root
            for i in p:
                if i not in cur.son:
                    # 不重复统计
                    cur.son[i] = TrieNode()
                cur = cur.son[i]
                cur.name = i
        
        treeExpressions = {} # 字典，检查是否出现相同的子树
        def gen_expression(node):
            if not node.son:
                return node.name
            
            curExpr = sorted('('+gen_expression(curSon)+')' for curSon in node.son.values()) # 排序，防止因访问顺序不同而造成的子树表达式不同
            subTreeExpr = ''.join(curExpr)
            if subTreeExpr in treeExpressions:
                node.deleted = True # 出现重复
                treeExpressions[subTreeExpr].deleted = True # 标记两个元素都删除
            else:
                treeExpressions[subTreeExpr] = node # 没有出现重复，需要记录字符串对应的节点，方便后面的判断
            return node.name+subTreeExpr # 记得加上当前节点

        for s in root.son.values():
            # 将每一个位于第1层的节点都计算一遍
            gen_expression(s)

        res = []
        path = []
        def dfs(node):
            # 还原未删除的文件夹
            if node.deleted:
                return
            path.append(node.name) # 维护路径
            res.append(path.copy())
            for s in node.son.values():
                dfs(s)
            path.pop() # 还原现场

        for s in root.son.values():
            # 对第1层每一个节点都还原一次
            dfs(s)

        return res

if __name__ == "__main__":
    s = Solution()
    paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
    print(s.deleteDuplicateFolder(paths))
