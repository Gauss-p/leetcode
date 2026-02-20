#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bank {
private:
    vector<long long> totBal;
    int n;

public:
    Bank(vector<long long>& balance) {
        totBal = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n || totBal[account1-1] < money){
            return false;
        }
        totBal[account1-1] -= money;
        totBal[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > n){
            return false;
        }
        totBal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n || totBal[account-1] < money){
            return false;
        }
        totBal[account-1] -= money;
        return true;
    }
};

int main(){
    vector<long long> balance = {10,100,20,50,30};
    Bank b(balance);
    vector<string> op = {"withdraw","transfer","deposit","transfer","withdraw"};
    vector<vector<int>> nums = {{3,10},{5,1,20},{5,20},{3,4,15},{10,50}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "withdraw"){
            cout << b.withdraw(nums[i][0], nums[i][1]) << endl;
        }
        if (op[i] == "transfer"){
            cout << b.transfer(nums[i][0], nums[i][1], nums[i][2]) << endl;
        }
        if (op[i] == "deposit"){
            cout << b.deposit(nums[i][0], nums[i][1]) << endl;
        }
    }
}
