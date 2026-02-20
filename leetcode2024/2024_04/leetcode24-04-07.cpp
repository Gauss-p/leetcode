#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class ThroneInheritance {
private:
    unordered_map<string, vector<string>> people;
    unordered_set<string> dead;
    string King;
public:
    ThroneInheritance(string kingName) {
        King = kingName;
    }
    
    void birth(string parentName, string childName) {
        people[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.emplace(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        function<void(string)> dfs = [&](string name){
            if (!dead.count(name)){
                res.push_back(name);
            }
            for (auto &s : people[name]){
                dfs(s);
            }
        };
        dfs(King);
        return res;
    }
};

int main(){
    return 0;
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
