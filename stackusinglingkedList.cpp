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

    bool isEmpty()
    {
        return top == NULL;
    }

};

int main()
{
    Stack stact;

    int choice = 0;
    int value;

    while (choice != 5)
    {

        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "5. Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the value to push : ";
                cin >> value;
                stact.push(value);
                break;
            case 2:
                if (!stact.isEmpty())
                {
                    stact.pop();
                }
                else
                {
                    cout << "Stact is Empty. Cannnot pop."
                    << endl;
                }
                break;
            case 3:
                if (!stact.isEmpty())
                {
                    stact.peek();
                }
                else
                {
                    cout << "Stact is Empety. No top Value."
                    << endl;
                }
                break;
            case 4:    
                cout << "Exiting Program." << endl;
                break;
            default:
                cout <<  "Invalid choice. Try again. " << endl;
                break;
        }
       
}