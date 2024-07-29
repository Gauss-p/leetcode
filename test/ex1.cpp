/*
 * ex1.cpp
 * 
 * Copyright 2023 gauss <gauss@GAUSS-COMPUTER>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
	stringstream ss;
	vector<string> goodWords = {"Hello", "Hey"};
	ss << "Hello World !";
	string tmp;
	while (ss >> tmp){
		cout << tmp << endl;
		cout << count(goodWords.begin(), goodWords.end(), tmp) << endl;
	}
	//~ vector<int> a{9,1,2,3};
	
	//~ sort(a.begin(), a.end());
	
	//~ for(int i:a)
        //~ cout << i << " ";

	//cout << a[0] << endl;
	//printf("hello world!");
	return 0;
}

