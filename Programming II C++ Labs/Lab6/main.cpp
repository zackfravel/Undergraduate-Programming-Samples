/* 
 * File:   main.cpp
 * Author: zpfravel
 *
 * Lab 6
 * 
 * Created on February 29, 2016, 1:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

//#define string Mystring

using namespace std;

void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl;
    cout << endl;
}

int main() 
{
    cout << "This is Lab 6" << endl;
    string s1 = "Hello, World!";
    string s1name = "s1";
    check(s1, s1name);
    check(s1, s1name);
    cout << "Lab 6 ends" << endl;
    return 0;
}

