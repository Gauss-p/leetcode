#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
private:
    string myBin(int d){
        string binD = bitset<32>(d).to_string();
        return binD.substr(binD.find('1'));
    }
public:
    string convertDateToBinary(string date) {
        return myBin(stoi(date.substr(0, 4)))+"-"+
               myBin(stoi(date.substr(5, 2)))+"-"+
               myBin(stoi(date.substr(8, 2)));
    }
};

int main(){
    Solution s;
    string date = "2080-02-09";
    cout << s.convertDateToBinary(date) << endl;
}
