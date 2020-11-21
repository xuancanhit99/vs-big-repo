#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node* left, * right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

struct Trunk
{
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p)
{
	if (p == nullptr)
		return;

	showTrunks(p->prev);

	cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
//void printTree(Node* root, Trunk* prev, bool isLeft)
//{
//	if (root == nullptr)
//		return;
//
//	string prev_str = "	";
//	Trunk* trunk = new Trunk(prev, prev_str);
//
//	printTree(root->left, trunk, true);
//
//	if (!prev)
//		trunk->str = "---";
//	else if (isLeft)
//	{
//		trunk->str = ".---";
//		prev_str = "   |";
//	}
//	else
//	{
//		trunk->str = "`---";
//		prev->str = prev_str;
//	}
//
//	showTrunks(trunk);
//	cout << root->data << endl;
//
//	if (prev)
//		prev->str = prev_str;
//	trunk->str = "   |";
//
//	printTree(root->right, trunk, false);
//}



void printSubtree(Node* root, const string& prefix)
{
	if (root == NULL)
	{
		return;
	}

	bool hasLeft = (root->left != NULL);
	bool hasRight = (root->right != NULL);

	if (!hasLeft && !hasRight)
	{
		return;
	}

	cout << prefix;
	cout << ((hasLeft && hasRight) ? "|--- " : "");
	cout << ((!hasLeft && hasRight) ? "|___ " : "");

	if (hasRight)
	{
		bool printStrand = (hasLeft && hasRight && (root->right->right != NULL || root->right->left != NULL));
		string newPrefix = prefix + (printStrand ? "|  " : "    ");
		cout << root->right->data << endl;
		printSubtree(root->right, newPrefix);
	}

	if (hasLeft)
	{
		cout << (hasRight ? prefix : "") << "|___ " << root->left->data << endl;
		printSubtree(root->left, prefix + "    ");
	}
}

void printTree(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << endl;
	printSubtree(root, "");
	cout << endl;
}


int main()
{
	Node* root = nullptr;

	// Construct above tree
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(15);

	// print constructed binary tree
	printTree(root);

	return 0;
}