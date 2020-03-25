/* 
 * Project: Lab 12
 * Author: Zack Fravel
 *
 * Created on April 18, 2016, 1:48 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


struct Node 
{ 
    int data; 
    Node* left; 
    Node* right;
}; 

Node* search(Node* t, int key, Node * & parent)
{
    if(t == NULL)
    {
        return NULL;
    }
    while(t != NULL)
    {
        if(t->data == key)
        {
            return t;
        }
        else if(key > t->data)
        {
            parent = t;
            t = t->right;
        }
        else if(key < t->data)
        {
            parent = t;
            t = t->left;
        }
    }
}

Node* insert(Node* t, int key)
{
    Node * ins = new Node();
    ins->data = key;
    ins->left = NULL;
    ins->right = NULL;
            
    if(t == NULL)
    {
        t = ins;
        return t;
    }else{
        Node * root;
        Node * s = search(t, key, root);
        if(s == NULL)
        {
            if (key < root->data)
            {
                root->left = ins;
            }else{
                root->right = ins;
            }
        }
    }
    return t;
}

void inorder (Node* t)
{
    if(t->left != NULL)
    {
        inorder(t->left);
    }
    cout << t->data << " ";
    if(t->right != NULL)
    {
        inorder(t->right);
    }
}

int main() 
{
    Node * tree = new Node();
    tree->data = 5;
    tree->left = NULL;
    tree->right = NULL;
    insert(tree, 1);
    insert(tree, 2);
    insert(tree, 7);
    insert(tree, 5); // duplicate
    insert(tree, 9);
    insert(tree, 3);
    inorder(tree);
    return 0;
}

