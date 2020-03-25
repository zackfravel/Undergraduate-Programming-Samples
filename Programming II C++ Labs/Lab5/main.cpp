/* 
 * File:   main.cpp
 * Author: zpfravel
 *
 * Created on February 22, 2016, 1:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void check (const string& s, const string& name)
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
    string s0, s2;
    check(s0, "s0");
    check(s2, "s2");
    bool emptyCheck = s0.empty();
    
    if(emptyCheck == 1)
        cout << "s0 is empty \n" << endl;
    else
        cout << "s0 is not empty \n" << endl;
    
    check(s0, "s0");
    string s1 = "Hello, World!";
    check(s1, "s1");
    s2 = s1;
    check(s2, "s2");
    s2.push_back('!');
    check(s2, "s2");
    s1+=s2;
    check(s1, "s1");
    s1.insert(13, " ");
    check(s1, "s1");
    s0 = s1 + " " + s2;
    check(s0, "s0");
    s0.reserve(50);
    check(s0, "s0");
    
    char c = s0[12];
    cout << "the value of c is " << c << "\n" << endl;
    check(s0, "s0");
    s2.append(s2);
    check(s2, "s2");
    s2.replace(12, 2, "=");
    check(s2, "s2");
    
    const char * p = s2.c_str();
    cout << "the value of p is: " << p << "\n" << endl;
    if(p == s2)
        cout << "p and s2 are the same!" << "\n" << endl;
    else
        cout << "p and s2 are not the same!" << "\n" << endl;
    
    check(p, "p");
    check(s2, "s2");
    
    s2[12] = s0[12];
    check(s2, "s2");
    
    s0.clear();
    s2.clear();
    check(s0, "s0");
    check(s2, "s2");
    cout << "the value of p is: " << p << endl;
    return 0;
}

