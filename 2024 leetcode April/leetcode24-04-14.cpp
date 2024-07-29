#include <iostream>
#include <unordered_map>
using namespace std;

class MyHashSet {
private:
    unordered_map<int, int> dic;
public:
    MyHashSet() {

    }
    
    void add(int key) {
        dic[key] = 1;
    }
    
    void remove(int key) {
        dic[key] = 0;
    }
    
    bool contains(int key) {
        return dic[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(){
    // ["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]
    // [[],[1],[2],[1],[3],[2],[2],[2],[2]]
    MyHashSet mhs;
    mhs.add(1);
    mhs.add(2);
    cout << mhs.contains(1) << " ";
    cout << mhs.contains(3) << " ";
    mhs.add(2);
    cout << mhs.contains(2) << " ";
    mhs.remove(2);
    cout << mhs.contains(2) << " ";
}
