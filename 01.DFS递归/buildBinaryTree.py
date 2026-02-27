class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

tot = [3,5,1,6,2,0,8,None,None,7,4]
def build(indx):
    cur = TreeNode(tot[indx])
    if indx*2+1 < len(tot) and tot[indx*2+1]:
        cur.left = build(indx*2+1)
    if indx*2+2 < len(tot) and tot[indx*2+2]:
        cur.right = build(indx*2+2)
    return cur
root = build(0)
