#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

class TaskManager {
private:
    unordered_map<int, vector<int>> task;
    priority_queue<tuple<int, int, int>> todo;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& ta : tasks){
            int u=ta[0], t=ta[1], p=ta[2];
            add(u, t, p);
            // task[t] = {u,p};
            // todo.push({p, t, u});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task[taskId] = {userId, priority};
        todo.emplace(priority, taskId, userId);
    }
    
    void edit(int taskId, int newPriority) {
        int curUserId = task[taskId][0];
        add(curUserId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        task[taskId][1] = -1;
    }
    
    int execTop() {
        while (!todo.empty()){
            auto [p, t, u] = todo.top();
            todo.pop();
            if (task[t][0]==u && task[t][1]==p){
                rmv(t);
                return u;
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> origion = {{1,101,10},{2,102,20},{3,103,15}};
    TaskManager tm(origion);
    vector<string> op = {"add","edit","execTop","rmv","add","execTop"};
    vector<vector<int>> num = {{4,104,5},{102,8},{},{101},{5,105,15},{}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "add"){
            tm.add(num[i][0], num[i][1], num[i][2]);
        }
        if (op[i] == "edit"){
            tm.edit(num[i][0], num[i][1]);
        }
        if (op[i] == "execTop"){
            cout << tm.execTop() << endl;
        }
        else{
            tm.rmv(num[i][0]);
        }
    }
}
