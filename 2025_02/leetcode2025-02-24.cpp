#include <iostream>
#include <vector>
#include <string>
using namespace std;

class OrderedStream {
private:
    vector<string> v;
    int ptr;
public:
    OrderedStream(int n) {
        v.resize(n+1, "");
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        int tmpid = ptr;
        vector<string> res;
        if (v[tmpid]!=""){
            res.push_back(v[tmpid]);
        }
        while (tmpid<v.size()-1 && v[tmpid]!="" && v[tmpid+1]!=""){
            tmpid++;
            res.push_back(v[tmpid]);
        }
        ptr += res.size();
        return res;
    }
};

int main(){
    OrderedStream os(5);
    vector<int> indxs = {3,1,2,5,4};
    vector<string> strs = {"ccccc","aaaaa","bbbbb","eeeee","ddddd"};
    for (int i=0; i<indxs.size(); i++){
        vector<string> res = os.insert(indxs[i], strs[i]);
        for (string& j : res){
            cout << j << " ";
        }
        cout << endl;
    }
}
