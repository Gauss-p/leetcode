#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
private:
    int ptr;
    vector<string> web;
public:
    BrowserHistory(string homepage) {
        ptr = 1;
        web.push_back(homepage);
    }
    
    void visit(string url) {
        // while (web.size()>ptr){
        //     web.erase(web.end()-1);
        // }
        web.resize(ptr);
        web.push_back(url);
        ptr++;
    }
    
    string back(int steps) {
        ptr = max(1, ptr-steps);
        return web[ptr-1];
    }
    
    string forward(int steps) {
        ptr = min((int)web.size(), ptr+steps);
        return web[ptr-1];
    }
};

int main(){
    BrowserHistory bh("leetcode.com");
    vector<string> ops = {"visit","visit","visit","back","back","forward","visit","forward","back","back"};
    vector<string> visits = {"google.com","facebook.com","youtube.com","linkedin.com"};
    vector<int> fb = {1,1,1,2,2,7};
    int v = 0, f = 0;
    for (auto& s : ops){
        if (s == "visit"){
            bh.visit(visits[v]);
            v++;
        }
        else if (s == "back"){
            cout << bh.back(fb[f]) << endl;
            f++;
        }
        else{
            cout << bh.forward(fb[f]) << endl;
            f++;
        }
    }
}
