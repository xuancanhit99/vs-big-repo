#include <iostream>
#include <fstream>
#define COUNT 10 
#define MAX 100

using namespace std;

class Node {
    const char* pathInput;
    const char* pathSearch;
    const char* pathDelete;
    unsigned long long key; // key is ISBN 
    string author, bookName;
    Node* left, * right;
public:
    int rotate = 0;
    // Default constructor.
    Node();

    // Parameterized constructor.
    Node(unsigned long long, string, string);

    // Create a new node
    Node* newNode(unsigned long long key);
    //

    // Get link-path to file Input, Search and Delete
    void getPath(const char*, const char*, const char*);


    // Insert function.
    Node* Insert(Node*, unsigned long long, string, string);


    // Rotate
    Node* rightRotate(Node* x);
    Node* leftRotate(Node* x);
    Node* splay(Node* root, unsigned long long key);

    // Inorder, PreOrder and PostOrder traversal.
    void Inorder(Node*);
    void PreOrder(Node* root);
    void PostOrder(Node* root);

    // Input key 
    void inputKey(unsigned long long key[], string nameBook[], string author[], int n);

    // create file inputTree.txt
    void createFileInput(unsigned long long key[], string nameBook[], string author[], int n);

    // Read file inputTree.txt and insert key to Tree
    Node* readFileInput(Node& tree, int& n);

    // create file searchKey.txt
    void createFileSearch(unsigned long long keySearch);

    // read file searchKey.txt and search key in Tree
    Node* readFileSearch(Node* root, Node tree);

    // create file deleteKey.txt
    void createFileDelete(unsigned long long keyDelete);

    // read file deleteKey.txt and delete key in Tree
    void readFileDelete(Node* root, Node tree);

    // delete 3 file inputTree.txt, searchKey.txt and deleteKey.txt
    void removeAllFile();

    // Display tree 2D
    void printSubtree(Node* root, const string& prefix);
    void printTree(Node* root);

    // Search key in Tree
    Node* search(Node* root, unsigned long long key);
    Node* Ssearch(Node* root, unsigned long long key);


    // Delete key in Tree
    Node* minValueNode(Node* root);
    Node* deleteNode(Node* root, unsigned long long key);
};

Node::Node() : key(0), left(NULL), right(NULL) {}

Node::Node(unsigned long long value, string bookName, string author) {
    key = value;
    this->bookName = bookName;
    this->author = author;
    left = right = NULL;
}

/* Helper function that allocates
a new Node with the given key and
    NULL left and right pointers. */
Node* Node::newNode(unsigned long long key) {
    Node* root = new Node();
    root->key = key;
    root->left = root->right = NULL;
    return (root);
}

Node* Node::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node* Node::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// This function brings the key at 
// root if key is present in tree.  
// If key is not present, then it 
// brings the last accessed item at  
// root. This function modifies the 
// tree and returns the new root  
Node* Node::splay(Node* root, unsigned long long key) {
    // Base cases: root is NULL or 
    // key is present at root  
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree  
    if (root->key > key) {
        // Key is not in tree, we are done  
        if (root->left == NULL) return root;

        // Zig-Zig (Left Left)  
        if (root->left->key > key) {
            // First recursively bring the 
            // key as root of left-left  
            root->left->left = splay(root->left->left, key);

            // Do first rotation for root,  
            // second rotation is done after else  
            rotate++;
            root = rightRotate(root);
        }
        else if (root->left->key < key) { // Zig-Zag (Left Right)  
            // First recursively bring 
            // the key as root of left-right  
            root->left->right = splay(root->left->right, key);

            // Do first rotation for root->left  
            if (root->left->right != NULL) {
                rotate++;
                root->left = leftRotate(root->left);
            }
        }

        // Do second rotation for root  
        if (root->left == NULL)
            return root;
        else {
            rotate++;
            return rightRotate(root);
        }

        //return (root->left == NULL) ? root : rightRotate(root);
    }
    else {
        // Key lies in right subtree  
        // Key is not in tree, we are done  
        if (root->right == NULL) return root;

        // Zag-Zig (Right Left)  
        if (root->right->key > key) {
            // Bring the key as root of right-left  
            root->right->left = splay(root->right->left, key);

            // Do first rotation for root->right  
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key) {// Zag-Zag (Right Right)  
            // Bring the key as root of  
            // right-right and do first rotation  
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        // Do second rotation for root  
        return (root->right == NULL) ? root : leftRotate(root);
    }
}


// The search function for Splay tree.  
// Note that this function returns the  
// new root of Splay Tree. If key is  
// present in tree then, it is moved to root.  
Node* Node::search(Node* root, unsigned long long key) {
    Node* s = NULL;
    int tempRotate = rotate;
    s = splay(root, key);
    this->rotate = tempRotate;
    return s;
}

Node* Node::Ssearch(Node* root, unsigned long long key) {
    if (root != NULL) {
        if (key == root->key)
            return root;
        if (key < root->key)
            return Ssearch(root->left, key);
        else
            return Ssearch(root->right, key);
    }
    else return NULL;
}


void Node::getPath(const char* pathInput, const char* pathSearch, const char* pathDelete) {
    this->pathInput = pathInput;
    this->pathSearch = pathSearch;
    this->pathDelete = pathDelete;
}

void Node::removeAllFile() {
    remove(pathInput);
    remove(pathSearch);
    remove(pathDelete);
}

Node* Node::Insert(Node* root, unsigned long long value, string nameBook, string author) {
    if (!root) {
        // Insert the first node, if root is NULL.
        return new Node(value, nameBook, author);
    }

    // Insert key.
    if (value > root->key) {
        // Insert right node key, if the 'value'
        // to be inserted is greater than 'root' node key.

        // Process right nodes.
        root->right = Insert(root->right, value, nameBook, author);
    }
    else {
        // Insert left node key, if the 'value'
        // to be inserted is greater than 'root' node key.

        // Process left nodes.
        root->left = Insert(root->left, value, nameBook, author);
    }

    // Return 'root' node, after insertion.
    return root;
}


/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
Node* Node::minValueNode(Node* root) {
    Node* current = root;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
Node* Node::deleteNode(Node* root, unsigned long long key) {
    // base case 
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node 
    // to be deleted 
    else {
        // node with only one child or no child 
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node 
        root->key = temp->key;

        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


void Node::Inorder(Node* root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

void Node::PreOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void Node::PostOrder(Node* root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
    }
}


// Enter input
void Node::inputKey(unsigned long long key[], string nameBook[], string author[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Please enter key[" << i + 1 << "]: "; cin >> key[i];
        cout << "Please enter Name Book[" << i + 1 << "]: "; cin >> nameBook[i];
        cout << "Please enter Author[" << i + 1 << "]: "; cin >> author[i];
    }
}

// Create file and write all key to file
void Node::createFileInput(unsigned long long key[], string nameBook[], string author[], int n) {
    ofstream fo(pathInput, ios::out | ios::app);
    for (int i = 0; i < n; i++) {
        fo << key[i] << " " << nameBook[i] << " " << author[i] << endl;
    }
    fo.close();
}

//Read file and add key to tree
Node* Node::readFileInput(Node& tree, int& n) {
    ifstream fi(pathInput);
    Node* root = NULL;
    unsigned long long key;
    string nameBook, author;
    if (!fi) {
        cout << "File Input not found." << endl;
        return NULL;
    }
    int count = 0;
    while (!fi.eof()) {
        fi >> key >> nameBook >> author;
        if (fi.eof()) break;
        if (count == 0) {
            root = tree.Insert(root, key, nameBook, author);
            count++;
        }
        else {
            tree.Insert(root, key, nameBook, author);
            count++;
        }
    }
    fi.close();
    n = count;
    return root;
}


void Node::createFileSearch(unsigned long long keySearch) {
    ofstream fo(pathSearch, ios::out | ios::app);
    fo << keySearch << " ";
    fo.close();
}

Node* Node::readFileSearch(Node* root, Node tree) {
    ifstream fi(pathSearch);
    //Node* tempRoot = NULL;
    unsigned long long keySearch;
    if (!fi) {
        cout << "File Search not found." << endl;
        return NULL;
    }
    while (!fi.eof()) {
        fi >> keySearch;
        if (fi.eof()) break;

        //Search all in file search
        /*if (tree.search(root, keySearch) == NULL)
            cout << keySearch << " does not exist in trees." << endl;
        else
            cout << keySearch << " found in trees." << endl;*/
    }
    
    //Search only one last elemment in file search
    if (tree.Ssearch(root, keySearch) == NULL)
            cout << keySearch << " does not exist in trees." << endl;
    
    else {
        root = tree.search(root, keySearch);
        cout << keySearch << " | Book: " << root->bookName << " | Author: " << root->author << ". found in trees." << endl;
    }
    fi.close();
    return root;
}


void Node::createFileDelete(unsigned long long keyDelete) {
    ofstream fo(pathDelete, ios::out | ios::app);
    fo << keyDelete << " ";
    fo.close();
}

void Node::readFileDelete(Node* root, Node tree) {
    ifstream fi(pathDelete);
    unsigned long long keyDelete;
    if (!fi) {
        cout << "File Delete not found." << endl;
        return;
    }
    while (!fi.eof()) {
        fi >> keyDelete;
        if (fi.eof()) break;
        root = tree.deleteNode(root, keyDelete);
    }
    fi.close();
}


void Node::printSubtree(Node* root, const string& prefix) {
    if (root == NULL)
        return;
    bool hasLeft = (root->left != NULL);
    bool hasRight = (root->right != NULL);
    if (!hasLeft && !hasRight)
        return;

    cout << prefix;
    cout << ((hasLeft && hasRight) ? "|--- " : "");
    cout << ((!hasLeft && hasRight) ? "|___ " : "");

    if (hasRight) {
        bool printStrand = (hasLeft && hasRight && (root->right->right != NULL || root->right->left != NULL));
        string newPrefix = prefix + (printStrand ? "|  " : "    ");
        cout << root->right->key << " : " << root->right->bookName << " : " << root->right->author << endl;
        printSubtree(root->right, newPrefix);
    }

    if (hasLeft) {
        cout << (hasRight ? prefix : "") << "|___ " << root->left->key << " : " << root->left->bookName << " : " << root->left->author << endl;
        printSubtree(root->left, prefix + "    ");
    }
}

void Node::printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->key << " : " << root->bookName << " : " << root->author << endl;
    printSubtree(root, "");
    cout << endl;
}
int main() {
    Node tree;
    Node* root = NULL;
    unsigned long long key[MAX];
    string author[MAX];
    string bookName[MAX];
    int n = 0;
    unsigned long long keySearch, keyDelete, keyInsert;
    string nameBookInsert, authorInsert;
    int sumInsert = 0;
    const char* pathInput = "C:/StudyInOut/AOD/Pr4_task3/inputTree.txt";
    const char* pathSearch = "C:/StudyInOut/AOD/Pr4_task3/searchKey.txt";
    const char* pathDelete = "C:/StudyInOut/AOD/Pr4_task3/deleteKey.txt";

    tree.getPath(pathInput, pathSearch, pathDelete);

    cout << "Welcome to the binary search tree manager program." << endl;
    while (1) {
        int choose;
        cout << "1. Create a Library(tree)." << endl;
        cout << "2. Insert book to library." << endl;
        cout << "3. Show Library." << endl;
        cout << "4. Search book in library." << endl;
        cout << "5. Remove the book in library." << endl;
        cout << "6. Delete all file and library." << endl;
        cout << "7. The number of rotations per total number of inserted keys(R/I)." << endl;
        cout << "8. Exit." << endl;
        cout << "Please choose: "; cin >> choose;
        switch (choose) {
        case 1:
            cout << "Please numbers of keys: "; cin >> n;
            tree.inputKey(key, bookName, author, n);
            tree.createFileInput(key, bookName, author, n);
            root = tree.readFileInput(tree, n);
            break;
        case 2:
            sumInsert++;
            cout << "Enter key you want insert: "; cin >> keyInsert;
            cout << "Enter Book Name you want insert: "; cin >> nameBookInsert;
            cout << "Enter Author you want insert: "; cin >> authorInsert;
            key[0] = keyInsert;
            bookName[0] = nameBookInsert;
            author[0] = authorInsert;
            tree.createFileInput(key, bookName, author, 1);
            root = tree.readFileInput(tree, n);
            root = tree.splay(root, keyInsert);
            break;
        case 3:
            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << endl << "Tree PreOrder: "; tree.PreOrder(root); cout << endl;
                cout << "Tree PostOrder: "; tree.PostOrder(root); cout << endl;
                cout << "Tree InOrder: "; tree.Inorder(root); cout << endl;
                cout << endl << "Library Book:" << endl;
                tree.printTree(root); cout << endl;
            }
            break;
        case 4:
            tree.readFileInput(tree, n);
            tree.readFileDelete(root, tree);
            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << "Enter the key to search: "; cin >> keySearch;
                tree.createFileSearch(keySearch);
                root = tree.readFileSearch(root, tree);
            }
            break;
        case 5:
            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << "Enter the key to delete: "; cin >> keyDelete;
                tree.createFileDelete(keyDelete);
                tree.readFileDelete(root, tree);
            }
            break;
        case 6:
            tree.removeAllFile();
            delete root;
            root = NULL;
            break;
        case 7:
            cout << "Rotate / Inserted = " << tree.rotate << "/" << sumInsert << endl << endl;
            break;
        case 8:
            return 1;
        default:
            cout << "You enter wrong! Please try again." << endl;
   
            break;
        }
    }
    return 0;
}
//202000000019 motorcycle robert
//202000000027 watership richardadams
//202000000036 lecture thelast
//202000000010 history bryson
//202000000064 forever haldeman
//202000000000 cuocdoi xuancanh
//202000000001 privet russian
//202000000015 theworld alex
