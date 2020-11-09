#include <iostream> 
using namespace std;

// Hash table size 
#define TABLE_SIZE 13 

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
        cout << key << " found" << endl;
    }

    // function to display the hash table 
    void displayHash() {
        cout << endl << "Hash Table" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (ISBN[i] != -1)
                cout << i << " --> "
                << ISBN[i] << " Book: " << nameBook[i] << " Author: " << author[i] << endl;
            else
                cout << i << endl;
        }
    }
};

int main() {
    // inserting keys into hash table 
    Book h;
    h.insertHash(202000000019, "Motorcycle", "Robert");
    h.insertHash(202000000027, "Watership", "RichardAdams");
    h.insertHash(202000000036, "Lecture", "TheLast");
    h.insertHash(202000000010, "History", "Bryson");
    h.insertHash(202000000064, "Forever", "Haldeman");

    // searching some keys 
    h.search(202000000036); // This key is present in hash table 
    h.search(202000000100); // This key does not exist in hash table 

    // display the hash Table 
    h.displayHash();
    return 0;
}