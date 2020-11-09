#include <iostream>
#include <stack>
#define COUNT 10 

using namespace std;

bool isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/';
}
int getPriority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}
bool isOperand(char x) {
    if ((x > 64 && x < 91) || (x > 96 && x < 123)) return true;
    return false;
}
string toPostfix(string& A) {
    stack<char> opStack;       //The stack is used to contain the operators ( ) + - * /
    string result = "";        //Creates an empty string, which will be the string to be returned
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(') {   //If it is "(" then add to the stack 
            opStack.push(A[i]);
        }
        else {
            if (isOperand(A[i])) {  //if it is operand a, b,c,d,e,f... add to string result
                result += A[i];
            }
            else {
                if (isOperator(A[i])) {  //If it is an operator, all operators have higher precedence than A[i] into result, then add A[i] to stack 
                
                    while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(A[i])){
                        result += opStack.top();
                        opStack.pop();
                    }
                    opStack.push(A[i]);
                }
                else {
                    if (A[i] == ')') {
                        while (!opStack.empty() && opStack.top() != '(') {
                            result += opStack.top();
                            opStack.pop();
                        }
                        opStack.pop();
                    }
                }
            }
        }
    }
    while (!opStack.empty()) {
        result += opStack.top();
        opStack.pop();
    }
    return result;
}
//Here, the string processing is complete, ie put the string into the suffix form, then we will put them into the tree
struct Node {
    char data;
    Node* Left;
    Node* Right;
    Node() {
        this->Left = this->Right = NULL;
    }
};
struct ExpressionTree {
    Node* Root;          //This binary tree only needs to capture the root node, the remaining nodes rely on the root node
    ExpressionTree() {
        this->Root = NULL;
    }
};
void showInfix(Node*& R) {
    if (R) {
        showInfix(R->Left);
        cout << R->data << " ";
        showInfix(R->Right);
    }
}
void showPostfix(Node*& R) {
    if (R) {
        showPostfix(R->Left);
        showPostfix(R->Right);
        cout << R->data << " ";
    }
}
void showPrefix(Node*& R) {
    if (R) {
        cout << R->data << " ";
        showPrefix(R->Left);
        showPrefix(R->Right);
    }
}

void addToExpression(Node*& R, string str) {
    str = toPostfix(str);
    stack<Node*> stackNode;
    for (int i = 0; i < str.size(); i++) {
        if (isOperand(str[i])) {
            Node* P = new Node;
            P->data = str[i];
            stackNode.push(P);
        }
        else {
            if (isOperator(str[i])) {
                Node* P = new Node;
                P->data = str[i];
                P->Right = stackNode.top();
                stackNode.pop();
                P->Left = stackNode.top();
                stackNode.pop();
                stackNode.push(P);
            }
        }
    }
    R = stackNode.top();
}


// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(Node* root, int space) {
    // Base case  
    if (root == NULL)
        return;

    // Increase distance between levels  
    space += COUNT;

    // Process right child first  
    print2DUtil(root->Right, space);

    // Print current node after space  
    // count  
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << endl;

    // Process left child  
    print2DUtil(root->Left, space);
}

// Wrapper over print2DUtil()  
void print2D(Node* root) {
    // Pass initial space count as 0  
    print2DUtil(root, 0);
}
int main() {
    ExpressionTree ET;
    string str;
    cout << "Enter expression, enter '#' to exit:" << endl;
    char a = 'h';
    while (a != '#') {
        cin >> a;
        if (a != '#') str += a;
    }
    addToExpression(ET.Root, str);
    cout << "\nPreFix: " << endl;
    showPrefix(ET.Root); cout << endl;
    cout << "\nPostFix: " << endl;
    showPostfix(ET.Root); cout << endl;
    cout << "\nInFix: " << endl;
    showInfix(ET.Root); cout << endl; 
    //Display the tree in 2D
    cout << endl << "Display Expression Tree:" << endl;
    print2D(ET.Root);
    return 0;
}