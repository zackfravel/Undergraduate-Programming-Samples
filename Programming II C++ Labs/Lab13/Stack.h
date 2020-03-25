// Stack.h
// Zack Fravel

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<typename S>
class Stack
{
public:
    // Constructors
    Stack();
    ~Stack();
    
    // Capacity
    bool empty() const; 
    unsigned int size() const; 
    
    // Element access
    S& top(); 
    const S& top() const; 
    
    // Modification
    void push(const S& x); 
    void pop();
    
    void print();
    
private:
    S* buffer;                // The dynamically-allocated array that holds the stack
    unsigned int numElements; // The number of elements currently on the stack
    unsigned int topIndex;    // The index of the top of the stack (0 initially)
};

// Constructors
    template<typename S>
    Stack<S>::Stack()
    {
        numElements = 0;
        buffer = new S[100];
        topIndex = -1;
    }
    
    template<typename S>
    Stack<S>::~Stack()
    {
        delete buffer;
    }
    
// Capacity
    template<typename S>
    bool Stack<S>::empty() const 
    {
        if(numElements == 0)
            return true;
        else
            return false;
    }
    
    template<typename S>
    unsigned int Stack<S>::size() const
    {
            return numElements;
    }
    
// Element access
    template<typename S>
    S& Stack<S>::top()
    {
        return buffer[topIndex];
    }
    
    template<typename S>
    const S& Stack<S>::top() const
    {
        return buffer[topIndex];
    }
    
// Modification
    template<typename S>
    void Stack<S>::push(const S& x)
    {
        numElements++;
        topIndex++;
        buffer[topIndex] = x;
    }
    
    template<typename S>
    void Stack<S>::pop()
    {
        numElements--;
        topIndex--;
    }
    
    template<typename S>
    void Stack<S>::print()
    {
        cout << "[ ";
        for (int i = 0; i < numElements; ++i)
        {
            cout << buffer[i] << " ";
        }
        cout << "]" << endl;
    }

#endif /* STACK_H */
