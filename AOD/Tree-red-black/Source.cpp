#include <iostream>
#include <cmath>
#include <string> 

using namespace std;
//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
struct StackNode
{
	int Number;
	StackNode* Next;
};

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
class Stack
{
public:
	// Constructors
	Stack();
	Stack(const Stack& stack);
	~Stack();

	// Methods
	bool IsFull();
	bool IsEmpty();
	void Push(int Number);
	void Pop(int& Number);
	void Top(int& Number);
	int GetLength();
	void Print();

private:
	StackNode* Head;
	int Length;
};


Stack::Stack()
{
	Head = NULL;
	Length = 0;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
Stack::Stack(const Stack& stack)
{
	// Create first node
	StackNode* copy = new StackNode();
	Head = copy;

	// Walk list to copy nodes
	StackNode* ptr = stack.Head;
	while (ptr != NULL)
	{
		copy->Next = new StackNode();
		copy = copy->Next;
		copy->Number = ptr->Number;
		copy->Next = NULL;
		ptr = ptr->Next;
	}

	// Tidy first node
	copy = Head;
	Head = copy->Next;
	delete copy;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
	// Walk stack deleting data
	while (Head != NULL)
	{
		StackNode* Temp = Head;
		Head = Head->Next;
		delete Temp;
	}

	// Reset head
	Head = NULL;
	Length = 0;
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
bool Stack::IsFull()
{
	return (false);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty()
{
	return (Length == 0);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void Stack::Push(int Number)
{
	// Check for full stack
	if (IsFull())
		return;

	// Allocate space for data
	StackNode* Temp = new StackNode;
	if (Temp == NULL)
		return;

	// Insert data at head of list
	Temp->Number = Number;
	Temp->Next = Head;
	Head = Temp;
	Length++;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
void Stack::Pop(int& Number)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Extract information from node
	Number = Head->Number;

	// Pop item from linked list
	StackNode* Temp = Head;
	Head = Head->Next;
	delete Temp;
	Length--;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
void Stack::Top(int& Number)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Return information from node
	Number = Head->Number;
}

//-----------------------------------------------------------
// Return the number of elements in stack.
//-----------------------------------------------------------
int Stack::GetLength()
{
	return Length;
}
//

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void Stack::Print()
{
	// Walk the stack printing data
	cout << "stack: ";
	StackNode* Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->Number << " ";
		Temp = Temp->Next;
	}
	cout << endl;
}

int main()
{
	Stack stack;
	string str;
	int num1, num2, res;

	cout << "Enter postfix Boolean expression: ";
	cin >> str;
	while (str != "?")
	{
		// Push integers on stack
		// Push true on stack
		if (str == "true") {
			stack.Push(1);
		}
		// Push false on stack
		else if (str == "false") {
			stack.Push(0);
		}
		// Integers
		else if ((str[0] >= '0') && (str[0] <= '9')) {
			stack.Push(stoi(str));
		}

		// Handle <
		else if (str == "<")
		{
			if (stack.GetLength() < 2)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 < num2);
		}

		// Handle <=
		else if (str == "<=")
		{
			if (stack.GetLength() < 2)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 <= num2);
		}

		// Handle >
		else if (str == ">")
		{
			if (stack.GetLength() < 2)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 > num2);
		}

		// Handle >=
		else if (str == ">=")
		{
			if (stack.GetLength() < 2)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 >= num2);
		}

		// Handle ==
		else if (str == "==")
		{
			if (stack.GetLength() < 2)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 == num2);
		}

		// Handle !=
		else if (str == "!=")
		{
			if (stack.GetLength() < 1)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 != num2);
		}

		// Handle ||
		else if (str == "||")
		{
			if (stack.GetLength() < 1)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 || num2);
		}

		// Handle &&
		else if (str == "&&")
		{
			if (stack.GetLength() < 1)
			{
				cout << "Error: Not enough data for '" << str << "' operation\n";
				return -1;
			}
			stack.Pop(num2);
			stack.Pop(num1);
			stack.Push(num1 && num2);
		}

		// Handle unexpected operation
		else
		{
			cout << "Error: Unexpected '" << str << "' in input\n";
			return -1;
		}
		cin >> str;
	}

	// Error checking on stack
	if (stack.GetLength() < 1)
	{
		cout << "Error: Not enough data for '" << str << "' operation\n";
		return -1;
	}
	else if (stack.GetLength() > 1)
	{
		cout << "Error: Too much data for '" << str << "' operation\n";
		return -1;
	}

	// Print result
	stack.Pop(res);
	if (res) {
		cout << "Result = true " << endl;
	}
	else {
		cout << "Result = false " << endl;
	}
	return 0;
}