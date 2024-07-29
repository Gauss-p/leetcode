#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    vector<int> dic;
    // unordered_map<int, int> dic;
    // set<int> s;
public:
    MyHashMap() {
        dic.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        // s.insert(key);
        dic[key] = value;
    }
    
    int get(int key) {
        // if (s.count(key) == 0) return -1;
        return dic[key];
    }
    
    void remove(int key) {
        dic[key] = -1;
    }
};

int main(){
    MyHashMap mhm;
    mhm.put(1, 1);
    cout << mhm.get(1) << endl;
    mhm.remove(1);
    cout << mhm.get(1) << endl;
}
