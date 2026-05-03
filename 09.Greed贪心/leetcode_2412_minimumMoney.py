from typing import List

class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        # 定义tot为所有交易中亏的总钱数，假设初始钱数为money，那么money中一定有一个tot，剩下的一部分就是用来应对每一份交易中的cost部分的。
        # 对于一份亏钱的交易，假设这是最后一份亏钱的交易，那么又因为当前的tot已经计算了当前亏的钱数，所以我们需要将当前亏的钱数减去再来判断money与cost的大小关系，即:money-(tot-(cost-cashback))>=cost。只有这样才能进行当前这一份亏钱的交易。整理可得:money-tot>=cashback
        # 对于一份赚钱的交易，假设这是在所有亏钱交易后的第一次赚钱交易，那么为了进行当前这一次交易，必须满足剩余的money大于等于当前cost。即:money-tot>=cost
        # 综上所述，当一份交易亏钱时，需满足money-tot>=cost=min(cost, cashback)，否则，当一份交易赚钱时，money-tot>=cashback=min(cost,cashback)。那么将所有交易都遍历完一遍后可以发现，money-cost至少为每一份交易的min(cost,cashback)的最大值(这是经过整理的情况，如果没有整理可以按照亏/赚钱来分类计算)
        ans = 0
        tot = 0
        for t in transactions:
            cost, cashback = t
            if cost>cashback:
                # 亏钱时
                tot += cost-cashback
                ans = ans if ans>cashback else cashback
            else:
                # 赚钱时
                ans = ans if ans>cost else cost
        return tot+ans

if __name__ == "__main__":
    s = Solution()
    transactions = [[2,1],[5,0],[4,2]]
    print(s.minimumMoney(transactions))
