#include "mystrlen.h"
using namespace std;

size_t mystrlen(const char* s)
{
    size_t length = 0;
    
    while(s[length] != '\0')
        length++;
    
    return length;
}