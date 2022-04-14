#include<iostream>
#include<string>
using namespace std;


struct Node
{
	char data;
	Node* pNext;
};
struct Stack
{
	Node* pHead = NULL;

};

Node* InitNode(char value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = value;
		p->pNext = NULL;
	}
	return p;
}
bool isEmpty(Stack s)
{
	return (s.pHead == NULL);
}
void push(Stack& s, char value)
{
	Node* p = InitNode(value);
	if (isEmpty(s))
	{
		s.pHead = p;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}
int Top(Stack s)
{
	if (isEmpty(s))
	{
		cout << "Stack is empty";
		return 0;
	}
	return s.pHead->data;

}
void Pop(Stack& s)
{
	if (!isEmpty(s))
	{
		int data = s.pHead->data;
		Node* p = s.pHead;
		s.pHead = s.pHead->pNext;
		delete p;

	}
	else
	{
		cout << "Stack is empty";

	}
}

void ExportStack(Stack s)
{
	for (Node* g = s.pHead; g; g = g->pNext)
	{
		cout << g->data << " ";
	}
	cout << endl;
}

bool checkstring(string str)
{	
	Stack s;
	int size = str.length();
	char token=' ';
	for (int i = 0; i < size; i++)
	{
		token = str[i];
		if (token == '(' || token == '[' || token == '{')
		{
			push(s, token);
		}
		else if (token == ')')
		{
			if (Top(s) == '(')
			{
				Pop(s);
			}
		}
		else if (token == ']')
		{
			if (Top(s) == '[')
			{
				Pop(s);
			}
		}
		else if (token == '}')
		{
			if (Top(s) == '{')
			{
				Pop(s);
			}
		}
	}
	if (isEmpty(s))
	{
		return true;
	}
	
	else
		return false;
}

int main()
{
	string str = "";
	getline(cin, str);
	if (checkstring(str))
	{
		cout << "Chuoi hop le";
	}
	else
	{
		cout << "Chuoi khong hop le";
	}
}