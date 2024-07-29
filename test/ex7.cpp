
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
	cout << endl;
    cout << ("100">"60") << endl;
	
    vector<string> vc = {"a", "b", "abc", "ad", "aba", "bdc"};
    vector<string> vc1 = {"0", "5", "110", "12", "101", "567", "100", "60"};
 
    sort(vc.begin(), vc.end());
    sort(vc1.begin(), vc1.end());
 
    for(auto &x : vc) {
        cout << x << " ";
    }
    cout << endl;
    for(auto &x : vc1) {
        cout << x << " ";
    }
    
    cout << endl;
    cout << ("100">"60") << endl;
 
    return 0;
}
