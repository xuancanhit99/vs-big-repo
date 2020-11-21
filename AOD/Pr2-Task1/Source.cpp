#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
using namespace std;

// Hash table size 
#define TABLE_SIZE 10000
//1

// Used in second hash function. 
#define PRIME 7 



class Book {
    // Pointer to an array containing buckets 
    unsigned long long* ISBN;
    string nameBook[TABLE_SIZE];
    string author[TABLE_SIZE];
    int curr_size;
public:
    // function to check if hash table is full 
    bool isFull() {

        // if hash size reaches maximum size 
        return (curr_size == TABLE_SIZE);
    }

    // function to calculate first hash 
    int hash1(unsigned long long key) {
        return (key % TABLE_SIZE);
    }

    // function to calculate second hash 
    int hash2(unsigned long long key) {
        return (PRIME - (key % PRIME));
    }

    Book() {
        ISBN = new unsigned long long[TABLE_SIZE];
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
            ISBN[i] = -1;
    }

    // function to insert key into hash table 
    void insertHash(unsigned long long key, string _nameBook, string _author) {
        // if hash table is full 
        if (isFull())
            return;

        // get index from first hash 
        int index = hash1(key);

        // if collision occurs 
        if (ISBN[index] != -1) {
            // get index2 from second hash 
            int index2 = hash2(key);
            int i = 1;
            while (1) {
                // get newIndex 
                int newIndex = (index + i * index2) % TABLE_SIZE;

                // if no collision occurs, store 
                // the key 
                if (ISBN[newIndex] == -1) {
                    ISBN[newIndex] = key;
                    nameBook[newIndex] = _nameBook;
                    author[newIndex] = _author;
                    break;
                }
                i++;
            }
        }

        // if no collision occurs 
        else {
            ISBN[index] = key;
            nameBook[index] = _nameBook;
            author[index] = _author;
        }
        curr_size++;
    }

    // function to search key in hash table 
    void search(unsigned long long key) {
        auto start = chrono::steady_clock::now();
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while (ISBN[(index1 + i * index2) % TABLE_SIZE] != key) {
            if (ISBN[(index1 + i * index2) % TABLE_SIZE] == -1) {
                cout << key << " does not exist" << endl;
                return;
            }
            i++;
        }
        cout << key << " found." << endl << "Book: " << nameBook[(index1 + i * index2) % TABLE_SIZE] << " | Author: " << author[(index1 + i * index2) % TABLE_SIZE] << endl;
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << "Runtime: " << chrono::duration <double>(diff).count() << " seconds" << endl;
    }

    // function to display the hash table 
    void displayHash() {
        cout << endl << "\t\tLibrary(Hash Table)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << setw(3) << "Num     " << setw(13) << "ISBN" << setw(15) << "Book Name" << setw(15) << "Author" << endl;
        cout << "----------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (ISBN[i] != -1)
                cout << setw(3) << i << " --> " << setw(13)
                << ISBN[i] << setw(15) << nameBook[i] << setw(15) << author[i] << endl;
            else
                cout << setw(3) << i << endl;
        }
    }
};

//InputBook
void inputFile(int numOfBook, unsigned long long arrKey[], string arrNameBook[], string arrAuthor[]) {
    for (int i = 0; i < numOfBook; i++) {
        cout << "Enter ISBN[" << i + 1 << "]: "; cin >> arrKey[i];
        cout << "Enter Book Name[" << i + 1 << "]: ";
        cin.ignore();
        getline(cin, arrNameBook[i]);
        cout << "Enter Author[" << i + 1 << "]: ";
        getline(cin, arrAuthor[i]);
    }
}

// Create file and write file
void createFile(const char* namef, int numOfBook, unsigned long long arrKey[], string arrNameBook[], string arrAuthor[]) {
    ofstream fo(namef, ios::out | ios::app);
    for (int i = 0; i < numOfBook; i++) {
        fo << arrKey[i] << " " << arrNameBook[i] << " : " << arrAuthor[i] << endl;
    }
    fo.close();
}

// Cut string nameBookAndAuthor -> nameBook, author
void analysisOfNameBookAndAuthor(string nameBookAndAuthor, string& nameBook, string& author) {
    int i;
    for (i = 0; i < nameBookAndAuthor.size(); i++)
        if (nameBookAndAuthor[i] == ':')
            break;
    nameBook.resize(i - 1);
    for (int j = 0; j < nameBook.size(); j++)
        nameBook[j] = nameBookAndAuthor[j];
    for (int k = 0; k < i + 2; k++)
        nameBookAndAuthor.erase(nameBookAndAuthor.begin());
    author = nameBookAndAuthor;
}

//Read file and add key to hash
void readFile(const char* namef, Book* h) {
    ifstream fi(namef);
    unsigned long long key;
    string nameBook;
    string author;
    string nameBookAndAuthor;
    if (!fi) {
        cout << "File no open" << endl;
        return;
    }
    while (!fi.eof()) {
        fi >> key;
        getline(fi, nameBookAndAuthor);
        nameBookAndAuthor.erase(nameBookAndAuthor.begin());
        if (fi.eof()) break;
        analysisOfNameBookAndAuthor(nameBookAndAuthor, nameBook, author);
        h->insertHash(key, nameBook, author);
    }
    fi.close();
}


//Read Library(file)
void readLibrary(int count, Book* h) {
    if (count > 1)
        h = new Book();
    readFile("C:/StudyInOut/AOD/Pr2_task1/inputBook.txt", h);
}

int main() {
    Book* h = new Book();
    int numOfBook;
    unsigned long long arrKey[TABLE_SIZE];
    string arrNameBook[TABLE_SIZE];
    string arrAuthor[TABLE_SIZE];
    cout << "Welcome to the library management program." << endl;
    int count = 1;
    while (1) {
        int choose;
        cout << "1. Import books into the library" << endl;
        cout << "2. Show all books available in the library" << endl;
        cout << "3. Find books in the library" << endl;
        cout << "4. Delete all library" << endl;
        cout << "Please choose: "; cin >> choose;
        switch (choose) {
        case 1:
            cout << "Enter number of book to be added to the library: "; cin >> numOfBook;
            inputFile(numOfBook, arrKey, arrNameBook, arrAuthor);
            createFile("C:/StudyInOut/AOD/Pr2_task1/inputBook.txt", numOfBook, arrKey, arrNameBook, arrAuthor);
            readLibrary(count, h);
            count++;
            break;
        case 2:
            readLibrary(count++, h);
            h = new Book();
            readFile("C:/StudyInOut/AOD/Pr2_task1/inputBook.txt", h);
            h->displayHash();
            break;
        case 3:
            
            unsigned long long keySearch;
            readLibrary(count++, h);
            cout << "Enter the book number(ISBN) you want to search: "; cin >> keySearch;
            h->search(keySearch);
            break;
        case 4:
            remove("C:/StudyInOut/AOD/Pr2_task1/inputBook.txt");
            h = new Book();
            break;
        default:
            cout << "You enter wrong! Please try again." << endl;
            break;
        }
        char c;
        cout << "Do you want continue(y/n): "; cin >> c; cout << endl;
        if (c == 'n' || c == 'N') break;
    }
    return 0;
}

// thiet ke lai Library chia cot dong dep hon
//202000000019 Motorcycle Robert
//202000000027 Watership RichardAdams
//202000000036 Lecture TheLast
//202000000010 History Bryson
//202000000064 Forever Haldeman
//
//202000000000 CuocDoi XuanCanh
//
//202000000001 CuocDoiAnh XuanCanh1
//202000000002 CuocDoiEm XuanCanh2
//
//202000000000 Cuoc Doi Xuan Canh