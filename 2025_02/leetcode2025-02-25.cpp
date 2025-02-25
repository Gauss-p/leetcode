#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Allocator {
private:
    vector<int> v;
public:
    Allocator(int n) {
        v.resize(n, 0);
    }
    
    int allocate(int size, int mID) {
        int cnt = 0;
        for (int i=0; i<v.size(); i++){
            if (v[i] > 0){
                cnt = 0;
                continue;
            }
            cnt++;
            if (cnt == size){
                for (int j=i-size+1; j<=i; j++){
                    v[j] = mID;
                }
                return i-size+1;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int res = 0;
        for (int i=0; i<v.size(); i++){
            if (v[i] == mID){
                v[i] = 0;
                res++;
            }
        }
        return res;
    }
};

int main(){
    Allocator alct(10);
    vector<string> op = {"allocate","allocate","allocate","freeMemory","allocate","allocate","allocate","freeMemory","allocate","freeMemory"};
    vector<vector<int>> nums = {{1,1},{1,2},{1,3},{2},{3,4},{1,1},{1,1},{1},{10,2},{7}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "allocate"){
            cout << alct.allocate(nums[i][0], nums[i][1]) << " ";
        }
        else{
            cout << alct.freeMemory(nums[i][0]) << " ";
        }
    }
    cout << endl;
}
