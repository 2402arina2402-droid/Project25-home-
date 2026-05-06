#include "String.h"
#include <iostream>
using namespace std;

int main() {

	String s1;
	String s2(50);
	String s3("Hello World!");
	String s4 = s3;

	cout << "Enter first string: " << endl;
	s1.input();
	cout << "First string: " << endl;
	s1.output();

	cout << "Enter second string: " << endl;
	s2.input();
	cout << "Second string: " << endl;
	s2.output();

	cout << "Third string: " << endl;
	s3.output();

	cout << "Fourth string (copy of third): " << endl;
	s4.output();

	cout << "Number of string objects: " << String::getCount() << endl;

	cout << "Intersection of first and second strings: " << endl;
	String s5 = s1 * s2;
	s5.output();

	int index;

	cout << "Enter index: ";
	cin >> index;

	if (index >= 0 && index < (int)s1) {
		cout << "Symbol: " << s1[index] << endl;
	}
	else {
		cout << "Wrong index";
	}

	int index = s1('a');

	if (index != -1) {
		cout << "Found at index: " << index;
	}
	else {
		cout << "Not found";
	}

	int length = s1;
	cout << "Length of s1 : " << length << endl;
}
