from typing import List
from collections import defaultdict
from sortedcontainers import SortedList

class MovieRentingSystem:
    # 对于每一个电影，我们都要存储所有的拥有它的商店和它的价格，同时我们还需要存储所有已经出租的电影的列表，最后，由于在删除和添加的时候需要知道价格，我们还需要一个字典存储指定商店，指定电影的价格
    def __init__(self, n: int, entries: List[List[int]]):
        self.movie_details = defaultdict(SortedList)
        self.out_movies = SortedList()
        self.total_movies = dict()
        for s, m, p in entries:
            self.total_movies[(s, m)] = p # 存储价格
            self.movie_details[m].add((p, s))

    def search(self, movie: int) -> List[int]:
        return [x[1] for x in self.movie_details[movie][:5]] # 用SortedList就可以维护价格最少的5个

    def rent(self, shop: int, movie: int) -> None:
        price = self.total_movies[(shop, movie)] # 先找到价格，然后再在其他两个列表中操作
        self.out_movies.add((price, shop, movie))
        self.movie_details[movie].discard((price, shop))

    def drop(self, shop: int, movie: int) -> None:
        price = self.total_movies[(shop, movie)] # 先找到价格，然后再在其他两个列表中操作
        self.movie_details[movie].add((price, shop))
        self.out_movies.discard((price, shop, movie))

    def report(self) -> List[List[int]]:
        return [[x[1], x[2]] for x in self.out_movies[:5]] # 用SortedList即可维护价格最少的5个借出电影

if __name__ == "__main__":
    tot = 3
    entries = [[0,1,5],[0,2,6],[0,3,7],[1,1,4],[1,2,7],[2,1,5]]
    mrs = MovieRentingSystem(tot, entries)
    op = ["search","rent","rent","report","drop","search"]
    num = [[1],[0,1],[1,2],[],[1,2],[2]]
    for i in range(len(op)):
        if op[i] == "search":
            print(mrs.search(num[i][0]))
        if op[i] == "rent":
            mrs.rent(num[i][0], num[i][1])
        if op[i] == "drop":
            mrs.drop(num[i][0], num[i][1])
        else:
            print(mrs.report())
