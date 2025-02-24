from typing import List

class OrderedStream:

    def __init__(self, n: int):
        self.lst = [""]*(n+1)
        self.ptr = 1

    def insert(self, idKey: int, value: str) -> List[str]:
        self.lst[idKey] = value
        tmpid = self.ptr
        res = []
        if self.lst[tmpid]!="":
            res.append(self.lst[tmpid])
        while tmpid<len(self.lst)-1 and self.lst[tmpid]!="" and self.lst[tmpid+1]!="":
            tmpid += 1
            res.append(self.lst[tmpid])
        self.ptr += len(res)
        return res

if __name__ == "__main__":
    os = OrderedStream(5)
    pairs = [[3,"ccccc"],[1,"aaaaa"],[2,"bbbbb"],[5,"eeeee"],[4,"ddddd"]]
    for p in pairs:
        print(os.insert(p[0], p[1]))
