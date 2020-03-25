/* 
 * File:   main.cpp
 * Author: wingning
 *         Zack Fravel
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node * current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// Print details about the given list in reverse order, one Node per line
void reverseShow(Node* tail)
{
    Node* current = tail;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    // Create the first node
    Node* head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    Node* tail = head;

    // Create a doubly linked list from the nodes
    for (int i = 1; i <= size; i++)
    {
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = tail;
        node->next = NULL;
        
        // Fold it into the list
        tail->next = node;
        
        // Move the tail
        tail = node;
    }
    show(head);
    reverseShow(tail);

    // TODO: Your code for steps 2-7 here.
    //(STEP 2)
    Node *n = new Node();
    n -> elem = 100;
    n -> next = head;
    head -> prev = n;
    head = n;
    head -> prev = NULL;
    show(head);
    reverseShow(tail);
    
    //(STEP 3)
    Node *m = new Node();
    m -> elem = -99;
    m -> prev = tail;
    tail -> next = m;
    tail = m;
    tail -> next = NULL;
    show(head);
    reverseShow(tail);
    
    //(STEP 4)
    Node *first = head -> next;
    first -> prev = NULL;
    delete head;
    head = first;
    show(head);
    reverseShow(tail);
    
    //(STEP 5)
    Node *last = tail -> prev;
    last -> next = NULL;
    delete tail;
    tail = last;
    show(head);
    reverseShow(tail);
    
    //(STEP 6 & 7)
    Node *tmp;
    Node *iter = tail;
    iter = tail;
    for(int k=0; k<3; k++)
    {
        Node *t = iter -> prev;
        iter = t;
        tmp = iter;
    }
    Node *o = new Node();
    o = tmp -> prev;
    o -> next = tmp -> next;
    o = tmp -> next;
    o -> prev = tmp -> prev;
    delete tmp;
    show(head);
    reverseShow(tail);
    
    // Clean up
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    
    return 0;
}