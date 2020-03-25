/* 
 * Project: Lab9.cpp
 * Author: Zack Fravel
 *
 * Created on March 28, 2016, 1:46 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int factorial(int n)
{
    int result = 0;
    
    if(n==1)
        result = 1;
    else
        result = n * factorial(n-1);
    
    return result;
}

int fibonacci(int n)
{
    int result;
    
    if(n == 0 || n == 1)
        result = 1;
    else
        result = fibonacci(n-1) + fibonacci(n-2);
    
    return result;
}

void sort (int * seq, int size)
{
    int temp = seq[0];
    int least = 0;
    if(size == 1)
    {
        cout << "List is sorted!" << endl;
    }else{
        for(int i = 0; i < size; i++)
        {
                if(seq[i] < temp)
                {
                    seq[0] = seq[i];
                    seq[i] = temp;
                    temp = seq[0];
                }
        }
        sort(seq+1, size-1);
    }
}

void display(int * seq, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << seq[i] << ",";
    }
    cout << endl;
}

int main() 
{
    //Factorial
    int fac = factorial(5);
    cout << fac << endl;
    
    //Fibonacci
    for(int i = 0; i < 10; i++)
    {
        int fib = fibonacci(i);
        cout << fib << ", ";
    }
    cout << endl;
    
    int array[10] = {8,2,6,7,9,5,1,3,0,4};
    
    //Display
    display(array, 10);
    
    //Sorting
    sort(array, 10);
    display(array, 10);
    
    return 0;
}

