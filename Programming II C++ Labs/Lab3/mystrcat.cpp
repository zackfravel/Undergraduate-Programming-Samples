#include "mystrcat.h"
using namespace std;

char * mystrcat(char * a, const char * b)
{
    int dest1 = 0;
    int dest2 = 0;
    
    while(a[dest1] != '\0')
    {
        dest1 ++;
    }
    
    while(b[dest2] != '\0')
    {
        a[dest1] = b[dest2];
        dest1++;
        dest2++;
    }
    
    a[dest1] = '\0';
    return a;
}

