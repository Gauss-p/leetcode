#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ATM {
private:
    vector<int> bank;
public:
    ATM() {
        bank.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i=0; i<5; i++){
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);
        vector<int> money = {20,50,100,200,500};
        int tot = 0;
        for (int i=4; i>=0; i--){
            if (1ll*bank[i]*money[i] <= 1ll*amount){
                amount -= 1ll*bank[i]*money[i];
                res[i] = bank[i];
            }
            else{
                res[i] += amount/money[i];
                amount -= 1ll*res[i]*money[i];
            }
        }
        if (amount == 0){
            for (int i=0; i<5; i++){
                bank[i] -= res[i];
            }
            return res;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

int main(){
    ATM atm;
    vector<string> op = {"d", "w", "d", "w", "w"};
    vector<vector<int>> d = {{0,0,1,2,1}, {0,1,0,1,1}};
    vector<int> w = {600, 600, 550};
    int di = 0, wi = 0;
    for (auto s : op){
        if (s == "d"){
            atm.deposit(d[di]);
            di++;
        }
        else{
            vector<int> res = atm.withdraw(w[wi]);
            wi++;
            for (auto i : res){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
