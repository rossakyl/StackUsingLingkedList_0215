#include <iostream> // Mengimpor pustaka untuk input/output
using namespace std; // Menggunakan namespace standar

class Node // Mendefinisikan class Node
{
public:  // akses modifier
    int data; // Menyimpan nilai data
    Node *next; // Pointer ke node berikutnya

    Node()
    {

        next = NULL; // Inisialisasi pointer next ke NULL
    }
};

class Stack // Mendefinisikan class Stack menggunakan linked list
{

private:
    Node *top; // Pointer ke elemen teratas stack
    
public:
    Stack()
    {

        top = NULL; // Inisialisasi stack kosong
    }    

    int push(int value) // Fungsi untuk menambahkan elemen ke atas stack
    {
        Node *newNode = new Node(); // Membuat node baru
        newNode->data = value; // Menyimpan data ke dalam node
        newNode->next = top; // Node baru menunjuk ke node sebelumnya
        top = newNode; // top sekarang menunjuk ke node baru
        cout << "Push Value: " << value << endl; // Menampilkan nilai yang ditambahkan
        return value; // Mengembalikan nilai yang ditambahkan
    }

    void pop() // Fungsi untuk menghapus elemen dari atas stack
    {
        if (isEmpty()) // Mengecek apakah stack kosong
        {

            cout << "Stack is Empty" << endl; // Menampilkan pesan jika kosong
        }

        cout << "Popped Value: " << top->data << endl;  //Menambah logika untuk memaparkan nilai yang dipop
    }

    void peek() // Menampilkan semua elemen dalam stack
    {
        if (top == NULL) // Mengecek apakah stack kosong
        {
            cout << "List is Empty." << endl; // Menampilkan pesan jika kosong
        }
        else
        {

            Node* current = top; // Memulai dari node paling atas
            while (current != NULL) // Selama node tidak NULL
            {
                cout << current->data << " " << endl; // Menampilkan data
                current = current->next; // Pindah ke node berikutnya
            }
            cout << endl; // Baris baru setelah menampilkan semua data
        }
    }

    bool isEmpty() // Mengecek apakah stack kosong
    {
        return top == NULL; // Mengembalikan true jika top adalah NULL
    }

};

int main() // Fungsi utama program
{
    Stack stact; // Membuat objek stack

    int choice = 0; // Variabel pilihan user
    int value; // Variabel untuk menyimpan nilai yang dimasukkan user

    while (choice != 5) // Looping selama pilihan bukan 5
    {

        cout << "1. Push\n"; // Menampilkan menu
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "5. Enter your choice : ";
        cin >> choice; // Menerima input pilihan user

        switch (choice) // Mengecek pilihan user
        {
            case 1:
                cout << "Enter the value to push : "; // Minta input nilai
                cin >> value; // Simpan nilai input
                stact.push(value); // Panggil fungsi push
                break;
            case 2:
                if (!stact.isEmpty()) // Jika stack tidak kosong
                {
                    stact.pop(); // Panggil fungsi pop
                }
                else
                {
                    cout << "Stact is Empty. Cannnot pop." // Tampilkan pesan jika kosong
                    << endl;
                }
                break;
            case 3:
                if (!stact.isEmpty()) // Jika stack tidak kosong
                {
                    stact.peek(); // Panggil fungsi peek
                }
                else
                {
                    cout << "Stact is Empety. No top Value." // Tampilkan pesan jika kosong
                    << endl;
                }
                break;
            case 4:    
                cout << "Exiting Program." << endl; // Keluar dari program
                break;
            default:
                cout <<  "Invalid choice. Try again. " << endl; // Tampilkan pesan untuk input tidak valid
                break;
        }
        cout << endl; // Baris baru antar iterasi
    }

    return 0; // Mengakhiri program
    
} 