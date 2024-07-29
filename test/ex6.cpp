#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <typeinfo>

using namespace std;

int main(){
	string s = "7868190130M7522";
	//~ stringstream ss;
	//~ ss << s.substr(11, 2);
	//~ int age;
	//~ ss >> age;
	//~ cout << age << endl;
	//~ cout << (age>60) << endl;
	
	//~ cout << ("100" > "60") << endl;
	
	string str_age = s.substr(11, 2);
	//~ int tmp_age = str_age-"0";
	//~ cout << tmp_age << endl;
	cout << typeid(str_age).name() << endl;
	cout << (str_age > "60") << endl;
	//~ cout << ("100" > "60") << endl;
	
	cout << endl;
    cout << ("100">"60") << endl;
	//~ cout << s << endl;
	//~ s = s.substr(11, 2);
	//~ cout << (s-"0") << endl;
	return 0;
}
