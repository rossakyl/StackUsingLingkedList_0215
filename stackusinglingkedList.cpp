#include <iostream>
using namespace std;

class Node
{
public:  // akses modifier
    int data;
    Node *next;

    Node()
    {

        next = NULL;
    }
};

class Stack
{

private:
    Node *top;
    
public:
    Stack()
    {

        top = NULL;
    }    

    int push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Push Value: " << value << endl;
        return value;
    }

    void pop()
    {
        if (isEmpty())
        {

            cout << "Stack is Empty" << endl;
        }

        cout << "Popped Value: " << top->data << endl;  //Menambah logika untuk memaparkan nilai yang dipop
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "List is Empty." << endl;       //Tetap menyertakan pengecekan isEmpty() agar tidak dereference top saat stack kosong
        }
        else
        {
            
            Node*current = top;
            while (current != NULL)
            {
                cout << current->data << " " << endl;
                current = current->next;
            }
            cout << endl;
        }
    }

    




};