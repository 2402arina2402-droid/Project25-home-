#pragma once
#include <iostream>

class String {
private:
    char* str;
    int size;
    static int count;
public:
    String();
    String(int size);
    String(const char* s);
    String(const String& other);
    ~String();

    void input();
    void output();

    static int getCount();

    friend String operator*(const String& s1, const String& s2);
};