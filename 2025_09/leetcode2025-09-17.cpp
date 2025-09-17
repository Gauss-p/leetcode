#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
private:
    unordered_map<int, set<int>> pos;
    unordered_map<int, int> num;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (num.count(index) == 0){
            num[index] = number;
            pos[number].insert(index);
        }
        else{
            int old = num[index];
            num[index] = number;
            pos[old].erase(index);
            pos[number].insert(index);
        }
    }
    
    int find(int number) {
        if (pos[number].size()>0){
            return *pos[number].begin();
        }
        return -1;
    }
};

int main(){
    NumberContainers nc;
    vector<string> op = {"find","change","change","change","change","find","change","find"};
    vector<vector<int>> nums = {{10},{2,10},{1,10},{3,10},{5,10},{10},{1,20},{10}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "find"){
            cout << nc.find(nums[i][0]) << endl;
        }
        else{
            nc.change(nums[i][0], nums[i][1]);
        }
    }
}
