#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> excel;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        excel[cell] = value;
    }
    
    void resetCell(string cell) {
        excel[cell] = 0;
    }
    
    int getValue(string formula) {
        int indx = 0;
        for (; indx<formula.size(); indx++){
            if (formula[indx] == '+'){
                break;
            }
        }
        string s1 = formula.substr(1, indx-1), s2 = formula.substr(indx+1, formula.size()-indx);
        int n1, n2;
        if (s1[0] >= 'A' && s1[0] <= 'Z'){
            n1 = excel[s1];
        }
        else{
            n1 = stoi(s1);
        }
        if (s2[0] >= 'A' && s2[0] <= 'Z'){
            n2 = excel[s2];
        }
        else{
            n2 = stoi(s2);
        }
        return n1+n2;
    }
};

int main(){
    int rows = 3;
    Spreadsheet s(rows);
    vector<string> op = {"getValue","setCell","getValue","setCell","getValue","resetCell","getValue"};
    vector<vector<string>> num = {{"=5+7"},{"A1","10"},{"=A1+6"},{"B2","15"},{"=A1+B2"},{"A1"},{"=A1+B2"}};
    for (int i=0; i<op.size(); i++){
        if (op[i] == "getValue"){
            cout << s.getValue(num[i][0]) << endl;
        }
        if (op[i] == "setCell"){
            s.setCell(num[i][0], stoi(num[i][1]));
        }
        else{
            s.resetCell(num[i][0]);
        }
    }
}
