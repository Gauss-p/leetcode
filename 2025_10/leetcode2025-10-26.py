from typing import List

class Bank:

    def __init__(self, balance: List[int]):
        self.totBal = balance
        self.n = len(balance)

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        n = self.n
        if account1 < 1 or account1 > n or account2 < 1 or account2 > n or money > self.totBal[account1-1]:
            return False
        self.totBal[account2-1] += money
        self.totBal[account1-1] -= money
        return True

    def deposit(self, account: int, money: int) -> bool:
        n = self.n
        if account < 1 or account > n:
            return False
        self.totBal[account-1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        n = self.n
        if account < 1 or account > n or money > self.totBal[account-1]:
            return False
        self.totBal[account-1] -= money
        return True

if __name__ == "__main__":
    balance = [10,100,20,50,30]
    b = Bank(balance)
    op = ["withdraw","transfer","deposit","transfer","withdraw"]
    nums = [[3,10],[5,1,20],[5,20],[3,4,15],[10,50]]
    for i in range(len(op)):
        if op[i] == "withdraw":
            print(b.withdraw(nums[i][0], nums[i][1]))
        if op[i] == "transfer":
            print(b.transfer(nums[i][0], nums[i][1], nums[i][2]))
        if op[i] == "deposit":
            print(b.deposit(nums[i][0], nums[i][1]))
