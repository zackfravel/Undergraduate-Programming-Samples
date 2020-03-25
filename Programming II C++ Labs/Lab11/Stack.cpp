#include "Stack.h"

// Constructors
    Stack::Stack()
    {
        numElements = 0;
        buffer = new int[100];
        topIndex = -1;
    }
    
    Stack::~Stack()
    {
        delete buffer;
    }
    
// Capacity
    bool Stack::empty() const 
    {
        if(numElements == 0)
            return true;
        else
            return false;
    }
    
    unsigned int Stack::size() const
    {
            return numElements;
    }
    
// Element access
    int& Stack::top()
    {
        return buffer[topIndex];
    }
    
    const int& Stack::top() const
    {
        return buffer[topIndex];
    }
    
// Modification
    void Stack::push(const int& x)
    {
        numElements++;
        topIndex++;
        buffer[topIndex] = x;
    }
    
    void Stack::pop()
    {
        numElements--;
        topIndex--;
    }
    
    void Stack::print()
    {
        cout << "[ ";
        for (int i = 0; i < numElements; ++i)
        {
            cout << buffer[i] << " ";
        }
        cout << "]" << endl;
    }