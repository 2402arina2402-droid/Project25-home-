#include "String.h"
#include <iostream>
using namespace std;

int String::count = 0;

String::String() : String(80) {}

String::String(int s) {
	size = s;
	str = new char[size];
	str[0] = '\0';
	count++;
}

String::String(const char* s) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	size = len + 1;
	str = new char[size];

	for (int i = 0; i < size; i++) {
		str[i] = s[i];
	}
	count++;
}

String::String(const String& other) {
	size = other.size;

	str = new char[size];
	if (other.str != nullptr) {
		strcpy_s(str, size, other.str);
	}
	else {
		str[0] = '\0';
	}

	count++;
}

String::~String() {
	if (str != nullptr) {
		delete[] str;
	}

	count--;
}

void String::input() {
	cout << "Enter string: ";
	cin.getline(str, size);
}

void String::output() {
	cout << "String: " << str << endl;
}

int String::getCount() {
	return count;
}

String operator*(const String& s1, const String& s2) {
	char* temp = new char[s1.size];
	int k = 0;

	for (int i = 0; s1.str[i] != '\0'; i++) {
		for (int j = 0; s2.str[j] != '\0'; i++) {
			if (s1.str[i] == s2.str[j]) {
				bool exist = false;
				for (int t = 0; t < k; t++) {
					if (temp[t] == s1.str[i]) {
						exist = true;
						break;
					}
				}
				if (!exist) {
					temp[k++] = s1.str[i];
				}
			}
		}
	}
	temp[k] = '\0';

	String result(temp);
	delete[] temp;

	return result;
}

char& String::operator[](int index) {
	return str[index];
}

int String::operator()(char c) {
	for (int i = 0; i < size; i++) {
		if (str[i] = c) {
			return i;
		}
	}
	return -1;
}

String::operator int() {
	int len = 0;

	while (str[len] != '\0') {
		len++;
	}
	return len;
}

