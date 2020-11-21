#include <iostream>
#include <fstream>
#define COUNT 10 
#define MAX 100

using namespace std;

class FileManager {
    const char* pathInputText;
    const char* pathInputBin;
    const char* pathSearchText;
    int key;
    FileManager* left, * right;
public:
    // Default constructor.
    FileManager();

    // Parameterized constructor.
    FileManager(int);

    // Get link-path to file Input, Search and Delete
    void getPath(const char*, const char*, const char*);


    // Insert function.
    FileManager* Insert(FileManager*, int);

    // Inorder, PreOrder and PostOrder traversal.
    void Inorder(FileManager*);
    void PreOrder(FileManager* root);
    void PostOrder(FileManager* root);

    // Input key from keyboard
    int inputKeyB(int arr[]);

    // Input key from file Text and create tree
    void readFileInput(int arr[], int& n);

    // Create file binary input
    void createFileInputBinary(int arr[], int n);

    // Read file binary input
    FileManager* readFileInputBin(FileManager& tree, int n);


    // create file searchKey.txt
    void createFileSearch(int keySearch);

    // read file searchKey.txt and search key in Tree
    void readFileSearch(FileManager* root, FileManager tree);

    // Search key in Tree
    FileManager* search(FileManager* root, int key);

    // delete 3 file inputTree.txt, searchKey.txt and deleteKey.txt
    void removeAllFile();

    // Display tree 2D
    void print2DUtil(FileManager* root, int space);
    void print2D(FileManager* root);
};

FileManager::FileManager() : key(0), left(NULL), right(NULL) {}

FileManager::FileManager(int value) {
    key = value;
    left = right = NULL;
}

void FileManager::getPath(const char* pathInputText, const char* pathSearchText, const char* pathInputBin) {
    this->pathInputBin = pathInputBin;
    this->pathInputText = pathInputText;
    this->pathSearchText = pathSearchText;
}

void FileManager::removeAllFile() {
    remove(pathInputText);
    remove(pathSearchText);
    remove(pathInputBin);
}

FileManager* FileManager::Insert(FileManager* root, int value) {
    if (!root) {
        // Insert the first node, if root is NULL.
        return new FileManager(value);
    }

    // Insert key.
    if (value > root->key) {
        // Insert right node key, if the 'value'
        // to be inserted is greater than 'root' node key.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else {
        // Insert left node key, if the 'value'
        // to be inserted is greater than 'root' node key.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}


void FileManager::Inorder(FileManager* root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

void FileManager::PreOrder(FileManager* root) {
    if (root != NULL) {
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void FileManager::PostOrder(FileManager* root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
    }
}

FileManager* FileManager::search(FileManager* root, int key) {
    if (root != NULL) {
        if (key == root->key)
            return root;
        if (key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    else return NULL;
}


// Input keyboard
int FileManager::inputKeyB(int arr[]) {
    int n;
    cout << "Please numbers of keys: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Please enter key[" << i + 1 << "]: "; cin >> arr[i];
    }
    return n;
}


// Read input file text
void FileManager::readFileInput(int arr[], int& n) {
    ifstream fi(pathInputText);
    if (!fi) {
        cout << "File no open" << endl;
        return;
    }
    int i = 0;
    while (!fi.eof()) {
        if (fi.eof()) break;
        fi >> arr[i];
        i++;
    }
    n = i;
    fi.close();
}

// Create file binary
void FileManager::createFileInputBinary(int arr[], int n) {
    ofstream fo(pathInputBin, ios::out | ios::binary);
    for (int i = 0; i < n; i++) {
        fo.write((char*)&(arr[i]), sizeof(arr[i]));
    }
    cout << endl << "Successfully created binary file." << endl;
    fo.close();
}

// Read input file binary
FileManager* FileManager::readFileInputBin(FileManager& tree, int n) {
    FileManager* root = NULL;
    string treeTemp;
    int key;
    ifstream fi(pathInputBin, ios::binary | ios::in);
    if (!fi) {
        cout << "Cannot open file" << endl;
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        fi.read((char*)&key, sizeof(key));
        if (i == 0)
            root = tree.Insert(root, key);
        else
            tree.Insert(root, key);
    }
    fi.close();
    return root;
}


void FileManager::createFileSearch(int keySearch) {
    ofstream fo(pathSearchText, ios::out | ios::app);
    fo << keySearch << " ";
    fo.close();
}

void FileManager::readFileSearch(FileManager* root, FileManager tree) {
    ifstream fi(pathSearchText);
    int keySearch;
    if (!fi) {
        cout << "File Search not found." << endl;
        return;
    }
    while (!fi.eof()) {
        fi >> keySearch;
        if (fi.eof()) break;

        //Search all in file search
        if (tree.search(root, keySearch) == NULL)
            cout << keySearch << " does not exist in trees." << endl;
        else
            cout << keySearch << " found in trees." << endl;
    }

    //Search only one last elemment in file search
    /*if (tree.search(root, keySearch) == NULL)
        cout << keySearch << " does not exist in trees." << endl;
    else
        cout << keySearch << " found in trees." << endl;*/
    fi.close();
}


// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void FileManager::print2DUtil(FileManager* root, int space) {
    // Base case  
    if (root == NULL)
        return;

    // Increase distance between levels  
    space += COUNT;

    // Process right child first  
    print2DUtil(root->right, space);

    // Print current node after space  
    // count  
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->key << endl;

    // Process left child  

    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()  
void FileManager::print2D(FileManager* root) {
    // Pass initial space count as 0  
    print2DUtil(root, 0);
}

int main()
{
    FileManager tree;
    FileManager* root = NULL;
    int key[MAX], n = 0;
    int keySearch;
    const char* pathInputText = "C:/StudyInOut/AOD/Pr4_task2/inputTreeText.txt";
    const char* pathSearchText = "C:/StudyInOut/AOD/Pr4_task2/searchKeyText.txt";
    const char* pathInputBin = "C:/StudyInOut/AOD/Pr4_task2/inputTreeBin.bin";

    tree.getPath(pathInputText, pathSearchText, pathInputBin);

    cout << "Welcome to the binary search tree manager program." << endl;
    while (1) {
        int choose;
        cout << "1. Input from the keyboard and create file binary." << endl;
        cout << "2. Input from file text and create file binary." << endl;
        cout << "3. Show tree." << endl;
        cout << "4. Search element in tree." << endl;
        cout << "5. Delete all data and trees." << endl;
        cout << "Please choose: "; cin >> choose;
        switch (choose) {
        case 1:
            n = tree.inputKeyB(key);
            tree.createFileInputBinary(key, n);
            root = tree.readFileInputBin(tree, n);
            break;

        case 2:
            tree.readFileInput(key, n);
            tree.createFileInputBinary(key, n);
            root = tree.readFileInputBin(tree, n);
            break;
        case 3:
            root = tree.readFileInputBin(tree, n);
            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << endl << "Tree PreOrder: "; tree.PreOrder(root); cout << endl;
                cout << "Tree PostOrder: "; tree.PostOrder(root); cout << endl;
                cout << "Tree InOrder: "; tree.Inorder(root); cout << endl;
                cout << "Tree 2D:" << endl;
                tree.print2D(root);
            }
            break;
        case 4:
            root = tree.readFileInputBin(tree, n);
            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << "Enter the key to search: "; cin >> keySearch;
                tree.createFileSearch(keySearch);
                tree.readFileSearch(root, tree);
            }
            break;
        case 5:
            tree.removeAllFile();
            delete root;
            root = NULL;
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