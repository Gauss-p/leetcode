#include <iostream>
#include <vector>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<long long> prod;
public:
    ProductOfNumbers() {
        prod = {1};
    }
    
    void add(int num) {
        if (num == 0){
            prod = {1};
        }
        else{
            prod.push_back(prod.back()*num);
        }
    }
    
    int getProduct(int k) {
        if (prod.size() <= k){
            return 0;
        }
        return prod.back()/prod[prod.size()-k-1];
    }
};

int main(){
    ProductOfNumbers pn;
    vector<string> op = {"add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"};
    vector<int> nums = {3,0,2,5,4,2,3,4,8,2};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "add"){
            pn.add(nums[i]);
        }
        else{
            cout << pn.getProduct(nums[i]) << endl;
        }
    }
}
