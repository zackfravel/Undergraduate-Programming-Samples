/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zpfravel
 *
 * Created on February 8, 2016, 1:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "mystrlen.h"
#include "mystrcat.h"


using namespace std;

int main() 
{
    char line[] = "ls -l -a | wc -c >> myfile";
    size_t len = strlen(line);
    cout << "The length of 'line' is..." << len << endl;
    
    char* strArray[10];
    for(int i; i < 10; i++)
    {
        strArray[i] = "\0";
    }
    
    int pieces = 0;
    char* ptr = strtok(line, " ");
    while(ptr != NULL)
    {
        strArray[pieces] = ptr;
        ptr = strtok(NULL, " ");
        pieces ++;
    }
    
    for(int i=0; i < pieces; i++)
    {
        cout << "strArray[" << i << "] = " << strArray[i] << endl;
    }
    
    size_t size = 0;
    for(int i=0; i < pieces; i ++)
    {
        size = size + strlen(strArray[i]);
    }
    
    //cout << size << endl;
    
    size_t numBlanks = len - size;
    
    cout << "The Number if blanks is..." << numBlanks << endl;
    
    char* result = new char[size + 1];
    result[0] = '\0';
    
    for(int i = 0; i < pieces; i++)
    {
        strcat(result, strArray[i]);
    }
    
    cout << "The concatenation of all strings in strArray is: " << result << endl;
    delete[] result;
    return 0;
}