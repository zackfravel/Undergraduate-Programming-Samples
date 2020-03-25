/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain, not used for lab 7
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }
    
    cout << "----------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    Node* head    = new Node();
    Node* current = head;

    // Create a linked list from the nodes
    for (int i = 0; i < size; i++)
    {
        current->elem = i;
        current->next = new Node();
        current       = current->next;
    }
    
    // Set the properties of the last Node (including setting 'next' to NULL)
    current->elem = size;
    current->next = NULL;
    show(head);

    // TODO: Your Code Here
    
    //Remove the first element from the linked list
    Node *first = head->next;
    delete head;
    head = first;
    show(head);
    
    //Remove the last element from the linked list
    current = head->next;
    Node* tmp = head;
    while (current->next != NULL)
    {
        tmp = current;
        Node* next = current->next;
        current = next;
    }
    Node* last;
    last = current;
    tmp->next = NULL;
    delete last;
    show(head);
    
    //Insert 10 elements to the beginning of the linked list
    for(int i = 0; i < 10; i++)
    {
        Node *n = new Node();
        n->elem = i;
        n->next = head;
        head = n;
    }
    show(head);
    
    //Insert 10 elements after the first node having value 7
    current = head;
    int y=0;
    while (current->next != NULL)
    {
        Node* m;
        Node* next = current->next;
        current = current->next;
        if(current->elem == 7 && y == 0)
        {
            m = current->next;
            for(int i=0; i<10; i++)
            {
                current->next = new Node();
                current = current->next;
                current->elem = i;
            } 
            current->next = m;
            y=1;
        }
    }
    show(head);
    // Clean up
    current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
