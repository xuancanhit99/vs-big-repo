#include <iostream>
#include <fstream>
#define COUNT 10 
#define MAX 100

using namespace std;

class BST {
    const char* pathInput;
    const char* pathSearch;
    const char* pathDelete;
    int key;
    BST* left, * right;
public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Get link-path to file Input, Search and Delete
    void getPath(const char*, const char*, const char*);


    // Insert function.
    BST* Insert(BST*, int);

    // Inorder, PreOrder and PostOrder traversal.
    void Inorder(BST*);
    void PreOrder(BST* root);
    void PostOrder(BST* root);

    // Input key 
    void inputKey(int key[], int n);

    // create file inputTree.txt
    void createFileInput(int key[], int n);

    // Read file inputTree.txt and insert key to Tree
    BST* readFileInput(BST& tree, int& n);

    // create file searchKey.txt
    void createFileSearch(int keySearch);

    // read file searchKey.txt and search key in Tree
    void readFileSearch(BST* root, BST tree);

    // create file deleteKey.txt
    void createFileDelete(int keyDelete);

    // read file deleteKey.txt and delete key in Tree
    void readFileDelete(BST* root, BST tree);

    // delete 3 file inputTree.txt, searchKey.txt and deleteKey.txt
    void removeAllFile();

    // Display tree 2D
    void print2DUtil(BST* root, int space);
    void print2D(BST* root);
    
    // Search key in Tree
    BST* search(BST* root, int key);
    BST* minValueNode(BST* root);

    // Delete key in Tree
    BST* deleteNode(BST* root, int key);
};

BST::BST() : key(0), left(NULL), right(NULL){}

BST::BST(int value) {
    key = value;
    left = right = NULL;
}

void BST::getPath(const char* pathInput, const char* pathSearch, const char* pathDelete) {
    this->pathInput = pathInput;
    this->pathSearch = pathSearch;
    this->pathDelete = pathDelete;
}

void BST::removeAllFile() {
    remove(pathInput);
    remove(pathSearch);
    remove(pathDelete);
}

BST* BST::Insert(BST* root, int value) {
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
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


void BST::Inorder(BST* root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

void BST::PreOrder(BST* root) {
    if (root != NULL) {
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void BST::PostOrder(BST* root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
    }
}

BST* BST::search(BST* root, int key) {
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

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
BST* BST::minValueNode(BST* root) {
    BST* current = root;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
BST* BST::deleteNode(BST* root, int key) {
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
    else
    {
        // node with only one child or no child 
        if (root->left == NULL)
        {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        BST* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node 
        root->key = temp->key;

        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Enter input
void BST::inputKey(int key[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Please enter key[" << i+1 << "]: "; cin >> key[i];
    }
}

// Create file and write all key to file
void BST::createFileInput(int key[], int n) {
    ofstream fo(pathInput, ios::out | ios::app);
    for (int i = 0; i < n; i++) {
        fo << key[i] << " ";
    }
    fo.close();
}

//Read file and add key to tree
BST* BST::readFileInput(BST& tree, int& n) {
    ifstream fi(pathInput);
    BST* root = NULL;
    string treeTemp;
    int key;

    if (!fi) {
        cout << "File Input not found." << endl;
        return NULL;
    }
    int count = 0;
    while (!fi.eof()) {
            fi >> key;
            if (fi.eof()) break;
            if (count == 0) {
                root = tree.Insert(root, key);
                count++;
            } 
            else {
                tree.Insert(root, key);
                count++;
            }
    }
    fi.close();
    n = count;
    return root;
}


void BST::createFileSearch(int keySearch) {
    ofstream fo(pathSearch, ios::out | ios::app);
    fo << keySearch << " ";
    fo.close();
}

void BST::readFileSearch(BST* root, BST tree) {
    ifstream fi(pathSearch);
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


void BST::createFileDelete(int keyDelete) {
    ofstream fo(pathDelete, ios::out | ios::app);
    fo << keyDelete << " ";
    fo.close();
}

void BST::readFileDelete(BST* root, BST tree) {
    ifstream fi(pathDelete);
    int keyDelete;
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


// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void BST::print2DUtil(BST* root, int space) {
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
void BST::print2D(BST* root) {
    // Pass initial space count as 0  
    print2DUtil(root, 0);
}

int main()
{
    BST tree;
    BST* root = NULL;
    int key[MAX], n = 0;
    int keySearch, keyDelete;
    const char* pathInput = "C:/StudyInOut/AOD/Pr4_task1/inputTree.txt";
    const char* pathSearch = "C:/StudyInOut/AOD/Pr4_task1/searchKey.txt";
    const char* pathDelete = "C:/StudyInOut/AOD/Pr4_task1/deleteKey.txt";
    
    tree.getPath(pathInput, pathSearch, pathDelete);

    cout << "Welcome to the binary search tree manager program." << endl;
    while (1) {
        int choose;
        cout << "1. Import elements into tree." << endl;
        cout << "2. Show tree." << endl;
        cout << "3. Search element in tree." << endl;
        cout << "4. Remove the element from the tree." << endl;
        cout << "5. Delete all data and trees." << endl;
        cout << "6. Exit." << endl;
        cout << "Please choose: "; cin >> choose;
        switch (choose) {
        case 1:
            cout << "Please numbers of keys: "; cin >> n;
            tree.inputKey(key, n);
            tree.createFileInput(key, n);
            root = tree.readFileInput(tree, n);
            break;
        case 2:
            root = tree.readFileInput(tree, n);
            tree.readFileDelete(root, tree);
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
        case 3:
            root = tree.readFileInput(tree, n);
            tree.readFileDelete(root, tree);

            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << "Enter the key to search: "; cin >> keySearch;
                tree.createFileSearch(keySearch);
                tree.readFileSearch(root, tree);
            }
            break;
        case 4:
            if (root == NULL)
                cout << "The tree has nothing!!!" << endl << endl;
            else {
                cout << "Enter the key to delete: "; cin >> keyDelete;
                if (tree.search(root, keyDelete) == NULL)
                    cout << keyDelete << " does not exist in trees." << endl << endl;
                root = tree.deleteNode(root, keyDelete);
                tree.createFileDelete(keyDelete);
                tree.readFileDelete(root, tree);
            }
            break;
        case 5:
            tree.removeAllFile();
            delete root;
            root = NULL;
            break;
        case 6:
            return 1;
        default:
            cout << "You enter wrong! Please try again." << endl;
            break;
        }
    }
    return 0;
}
//202000000019 Motorcycle Robert
//202000000027 Watership RichardAdams
//202000000036 Lecture TheLast
//202000000010 History Bryson
//202000000064