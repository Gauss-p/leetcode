#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Skiplist {
private:
    unordered_map<int, int> mp;
public:
    Skiplist() {
        
    }
    
    bool search(int target) {
        return mp[target]!=0;
    }
    
    void add(int num) {
        mp[num]++;
    }
    
    bool erase(int num) {
        if (mp[num]==0) return false;
        mp[num]--;
        return true;
    }
};

int main(){
    Skiplist s;
    vector<string> op = {"add","add","add","search","add","search","erase","erase","search"};
    vector<int> nums = {1,2,3,0,4,1,0,1,1};
    for (int i=0; i<nums.size(); i++){
	if (op[i] == "add"){
	    s.add(nums[i]);
	}
	else if (op[i] == "search"){
	    cout << s.search(nums[i]) << endl;
	}
	else{
	    cout << s.erase(nums[i]) << endl;
	}
    }
}
