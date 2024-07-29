#include <iostream>
#include <bitset>

using namespace std;

int main(){
	int n = 6;
	cout << bitset<7>(n) << endl;
	cout << bitset<7>(-n) << endl;
	cout << bitset<7>(n&(-n)) << endl;
	int tmp = n&(-n);
	cout << tmp << endl;
	cout << bitset<8>(10&2) << endl;
	return 0;
}
