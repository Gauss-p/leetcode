#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	vector<int> nums = {7,52,2,4};
	cout << *nums.begin() << *(nums.end()-1) << endl;
	nums.erase(nums.begin());
	nums.erase(nums.end()-1);
	cout << *nums.begin() << *(nums.end()-1) << endl;
	
	stringstream ss;
	ss << 1;
	ss << 2;
	int tmp;
	ss >> tmp;
	cout << ss.str() << endl;
	cout << tmp+1 << endl;
	return 0;
}
