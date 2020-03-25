/* 
 * Project: Lab 14
 * Author: Zack Fravel
 *
 * Created on May 2, 2016, 1:34 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

// Generate random alphanumeric keys in [min,max] range
// min >= 1. Current alphabet includes 0 to 9, a to z, A to Z, and _ -
string randomKey(unsigned int min, unsigned int max)
{
    const int SIZE = 64;
    const char alphabet[SIZE]={'0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
    'Y','Z','-','_'};

    // simple error handling
    if (min == 0)
        min = 1;
    if (max < min)
        max = min;

    // pick a length between min and max
    int lenRange = max - min + 1;    
    int len      = rand() % lenRange;
    len          = len + min;

    // len is one of min, min+1,...max
    string s;
    for (int i = 0; i < len; i++)
        s.push_back(alphabet[rand() % SIZE]);
    
    return s;
}

size_t char64(char c)
{
    if(c >= '0' && c<= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if(c >= 'a' && c <= 'z')
        return c - 'a' + 36;
    else if(c == '-')
        return 62;
    else if(c == '_')
        return 63;
    return 0;
}

size_t dmHash(string key, size_t tableSize)
{
    // int -> ASCII
    // val = char64[i] -> val = (64 * val)%tableSize + char64[i+1]
    // Do this for whole string, return final val%tableSize
    
    int val = 0;

    for(int i = 0; i < key.length(); i++)
    {
        val = (64 * val) % tableSize;
        val = val + char64(key[i]);
    }
    
    return val % tableSize;
}

size_t mmHash(string key, size_t tableSize)
{
    // int -> ASCII
    // ASCII * multiplier
    // cast double to int and subtract the whole # to get "fractional part"
    // fractional * tableSize <-- return this
    
    double val = 0;
    double golden_ratio = 0.61803398875;
    
    for(int i = 0; i < key.length(); i++)
    {
        val = 64 * val + char64(key[i]);
    }
    
    val *= golden_ratio;
    val = val - int(val); // get fractional part
    
    return val * tableSize;
}

int main() 
{
    
    //  TESTING HASH FUNCTIONS  //
    cout << dmHash("a9B34", 103981) << endl; 
    cout << mmHash("a9B34", 103981) << endl; 
    cout << dmHash("a9B34uvwXYZ1234500", 103981) << endl; // prints 40643. 
    cout << mmHash("a9B34uvwXYZ1234500", 103981) << endl; // prints 90101.  OVERFLOW
    cout << dmHash("zyxwvutsrqpo", 103981) << endl; // prints 79631. 
    cout << mmHash("zyxwvutsrqpo", 103981) << endl; // prints 53532.  OVERFLOW
    
    // HASH TABLE SIMULATOR //
    
    string keys[15000];
    for(int i = 0; i < 15000; i++)
    {
        keys[i] = randomKey(12,12);
        bool unique = true;
        for(int k = 0; k < i; k++)
        {
            if(keys[i] == keys[k])
            {
                unique = false;
                break;         
            }
        }
        if(!unique)
        {
            i--;
        }
    }
    
    int H[103981];
    int collisions = 0; // sum of all slots > 1 (minus 1 in each case)
    int lists = 0; // number of slots > 1
    int maxLength = 0; // biggest value in any slot
    
    for(int i; i < 103981; i++)
    {
        H[i] = 0;
    }
    
    for(int i; i < 15000; i++)
    {
        H[dmHash(keys[i], 103981)]++;
    }
    
    for(int i; i < 103981; i++)
    {
        if(H[i] > 1)
        {
            lists++;
        }
        
        if(H[i] > 1)
        {
            collisions += H[i] - 1;
            maxLength = H[i];
            while(maxLength < H[i])
                maxLength = H[i];
        }
    }
    
    cout << "collisions: " << collisions << endl;
    cout << "Linked Lists: " << lists << endl;
    cout << "Max List Length: " << maxLength << endl;
    
    return 0;
}

