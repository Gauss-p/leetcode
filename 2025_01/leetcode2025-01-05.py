from typing import List

class ATM:

    def __init__(self):
        self.bank = [0]*5

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.bank[i] += banknotesCount[5-i-1]

    def withdraw(self, amount: int) -> List[int]:
        res = [0]*5
        money = [500,200,100,50,20]
        tot = 0
        for i in range(5):
            if self.bank[i]*money[i] <= amount:
                amount -= self.bank[i]*money[i]
                res[i] = self.bank[i]
            else:
                res[i] += amount//money[i]
                amount -= res[i]*money[i]
        if amount == 0:
            for i in range(5):
                self.bank[i] -= res[i]
            return res[::-1]
        return [-1]


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)

if __name__ == "__main__":
    atm = ATM()
    op = ['d','w','d','w','w']
    d = [[0,0,1,2,1],[0,1,0,1,1]]
    w = [600,600,550]
    di,wi = 0,0
    for s in op:
        if s == 'd':
            atm.deposit(d[di])
            di += 1
        else:
            print(atm.withdraw(w[wi]))
            wi += 1
