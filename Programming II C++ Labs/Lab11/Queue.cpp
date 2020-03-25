#include "Queue.h"
// Constructors
    Queue::Queue()
    {
        head = NULL;
        tail = NULL;
        numElements = 0;
    }
    
    Queue::~Queue()
    {
        while(!empty())
        {
            pop();
        }
    }
    
// Capacity
    bool Queue::empty() const
    {
        return numElements == 0;
    }
    
    unsigned int Queue::size() const
    {
        return numElements;
    }
    
// Element access
    int& Queue::front()
    {
        return head->elem;
    }
    
    const int& Queue::front() const
    {
        return head->elem;
    }
    
    int& Queue::back()
    {
        return tail->elem;
    }
    
    const int& Queue::back() const
    {
        return tail->elem;
    }
    
// Modification
    void Queue::push(const int& x)
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
    
    void Queue::pop()
    {
        Node * n = head->next;
        delete head;
        head = n;
        numElements--;
    }

    void Queue::print()
    {
        cout << "[ ";
        for (Node* cur = head; cur != NULL; cur = cur->next)
        {
            cout << cur->elem << " ";
        }
        cout << "]" << endl;
    }