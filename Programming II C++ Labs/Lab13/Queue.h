// Queue.h
// Zack Fravel


#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <iostream>
using namespace std;

// Basic Node structure
template<typename N>
struct Node
{
    N elem;    // Data
    Node * next; // Pointer to the next node in the chain
};

template<typename Q>
class Queue
{
public:
    // Constructors
    Queue();
    ~Queue();
    
    // Capacity
    bool empty() const; 
    unsigned int size() const; 
    
    // Element access
    Q& front(); 
    const Q& front() const; 
    Q& back(); 
    const Q& back() const; 
    
    // Modification
    void push(const Q& x);
    void pop();

    void print();
    
private:
    struct Node
    {
        Q elem;           // Data
        Node * next;        // Pointer to the next node in the chain
    };
    Node * head;               // The front of the queue
    Node * tail;               // The end of the queue
    unsigned int numElements; // The number of elements in the queue
};

// Constructors
    template<typename Q>
    Queue<Q>::Queue()
    {
        head = NULL;
        tail = NULL;
        numElements = 0;
    }
    
    template<typename Q>
    Queue<Q>::~Queue()
    {
        while(!empty())
        {
            pop();
        }
    }
    
// Capacity
    template<typename Q>
    bool Queue<Q>::empty() const
    {
        return numElements == 0;
    }
    
    template<typename Q>
    unsigned int Queue<Q>::size() const
    {
        return numElements;
    }
    
// Element access
    template<typename Q>
    Q& Queue<Q>::front()
    {
        return head->elem;
    }
    
    template<typename Q>
    const Q& Queue<Q>::front() const
    {
        return head->elem;
    }
    
    template<typename Q>
    Q& Queue<Q>::back()
    {
        return tail->elem;
    }
    
    template<typename Q>
    const Q& Queue<Q>::back() const
    {
        return tail->elem;
    }
    
// Modification
    template<typename Q>
    void Queue<Q>::push(const Q& x)
    {
        numElements++;
        Node * n = new Node;
        n->elem = x;
        if(tail != NULL)
            tail->next = n;
        else
            head = n;
        tail = n;
    }
    
    template<typename Q>
    void Queue<Q>::pop()
    {
        Node * n = head->next;
        delete head;
        head = n;
        numElements--;
    }

    template<typename Q>
    void Queue<Q>::print()
    {
        cout << "[ ";
        for (Node* cur = head; cur != NULL; cur = cur->next)
        {
            cout << cur->elem << " ";
        }
        cout << "]" << endl;
    }

#endif /* QUEUE_H */