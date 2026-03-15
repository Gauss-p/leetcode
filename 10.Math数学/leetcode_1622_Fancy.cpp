#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Fancy {
private:
    vector<int> lst;
    long long mulNum, addNum, modNum;

    long long quickPow(long long a, int b){
        long long res = 1;
        while (b){
            if (b&1){
                res = (res*a)%modNum;
            }
            a = (a*a)%modNum;
            b >>= 1;
        }
        return res;
    }
public:
    Fancy() {
        mulNum = 1ll;
        addNum = 0ll;
        modNum = (long long)1e9+7;
    }
    
    void append(int val) {
        lst.push_back(((val-addNum+modNum)*quickPow(mulNum, modNum-2))%modNum);
    }
    
    void addAll(int inc) {
        addNum += inc;
    }
    
    void multAll(int m) {
        addNum = (addNum*m)%modNum;
        mulNum = (mulNum*m)%modNum;
    }
    
    int getIndex(int idx) {
        if (idx >= lst.size()){
            return -1;
        }
        return ((1ll*lst[idx]*mulNum)%modNum+addNum)%modNum;
    }
};

int main(){
    Fancy f;
    vector<string> ops = {"append","addAll","append","multAll","getIndex","addAll","append","multAll","getIndex","getIndex","getIndex"};
    vector<int> nums = {2,3,7,2,0,3,10,2,0,1,2};
    for (int i=0; i<ops.size(); i++){
        if (ops[i] == "append"){
            f.append(nums[i]);
        }
        else if (ops[i] == "addAll"){
            f.addAll(nums[i]);
        }
        else if (ops[i] == "multAll"){
            f.multAll(nums[i]);
        }
        else{
            cout << f.getIndex(nums[i]) << endl;
        }
    }
}
